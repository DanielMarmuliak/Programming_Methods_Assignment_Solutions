#include "f_match.h"

#include <cmath>
#include <stdexcept>

namespace
{
    // Liczba parametrów modelu na początku każdego wiersza.
    constexpr int f_parameter_count = 6;

    // Liczba punktów siatki, które porównujemy po pominięciu parametrów.
    constexpr int f_expected_point_count = 100;
}

// Oblicza błąd dopasowania pomiędzy siatką nieznaną
// a jedną siatką wzorcową.
//
// Porównywane są tylko współrzędne punktów,
// czyli elementy od indeksu 6 do końca.
// Pierwsze 6 wartości to parametry modelu i nie są
// uwzględniane w obliczeniach.
//
// Funkcja sumuje kwadraty różnic dla współrzędnych Y i X,
// a na końcu zwraca pierwiastek z tej sumy.
double f_compute_mse(const Grid& unknown_grid, const Grid& candidate_grid)
{
    // Obie siatki muszą mieć taki sam rozmiar, aby można je było porównać.
    if (unknown_grid.y_row.size() != candidate_grid.y_row.size() ||
        unknown_grid.x_row.size() != candidate_grid.x_row.size())
    {
        throw std::runtime_error("Compared grids must have the same size.");
    }

    double sum = 0.0;

    // Pomijamy pierwsze 6 wartości, bo są to parametry modelu.
    for (std::size_t i = f_parameter_count; i < unknown_grid.y_row.size(); ++i)
    {
        const double dy = unknown_grid.y_row[i] - candidate_grid.y_row[i];
        const double dx = unknown_grid.x_row[i] - candidate_grid.x_row[i];

        // Dodajemy kwadraty różnic dla Y i X.
        sum += dy * dy;
        sum += dx * dx;
    }

    // Sprawdzamy, czy po parametrach pozostało dokładnie 100 punktów.
    const std::size_t point_count = unknown_grid.y_row.size() - f_parameter_count;
    if (point_count != static_cast<std::size_t>(f_expected_point_count))
    {
        throw std::runtime_error("Each grid should contain exactly 100 points after 6 parameters.");
    }

    return std::sqrt(sum);
}

// Wyszukuje najlepiej dopasowaną siatkę spośród wszystkich siatek wzorcowych.
// Dla każdej siatki:
// 1. oblicza wartość błędu dopasowania,
// 2. zapisuje tę wartość do listy wyników,
// 3. porównuje ją z dotychczasowym minimum.
//
// Funkcja zwraca strukturę MatchResult zawierającą:
// - wszystkie obliczone błędy,
// - indeks najlepszego dopasowania,
// - minimalną wartość błędu,
// - najlepiej dopasowaną siatkę.
MatchResult f_find_best_match(const Grid& unknown_grid, const std::vector<Grid>& candidate_grids)
{
    if (candidate_grids.empty())
    {
        throw std::runtime_error("Candidate grid list is empty.");
    }

    MatchResult result;
    result.mse_values.reserve(candidate_grids.size());

    for (std::size_t i = 0; i < candidate_grids.size(); ++i)
    {
        const double mse = f_compute_mse(unknown_grid, candidate_grids[i]);
        result.mse_values.push_back(mse);

        // Jeśli to pierwsza siatka albo znaleziono mniejszy błąd,
        // zapisujemy nowe najlepsze dopasowanie.
        if (result.best_index == -1 || mse < result.best_mse)
        {
            result.best_index = static_cast<int>(i);
            result.best_mse = mse;
            result.best_grid = candidate_grids[i];
        }
    }

    return result;
}
