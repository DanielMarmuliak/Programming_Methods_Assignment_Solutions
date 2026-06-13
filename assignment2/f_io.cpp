#include "f_io.h"

#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdexcept>

// Zamienia jeden wiersz tekstu na wektor liczb typu double.
// Funkcja rozdziela dane po spacjach i zapisuje wszystkie liczby
// do wektora w tej samej kolejności, w jakiej występują w pliku.
std::vector<double> f_parse_line(const std::string& line)
{
    std::vector<double> values;
    std::istringstream input(line);
    double value = 0.0;

    while (input >> value)
    {
        values.push_back(value);
    }

    return values;
}

// Odczytuje wszystkie siatki z pliku tekstowego.
// Każda siatka jest zapisana w dwóch kolejnych wierszach:
// - pierwszy wiersz zawiera wartości Y,
// - drugi wiersz zawiera wartości X.
// Funkcja:
// 1. otwiera plik,
// 2. odczytuje wszystkie niepuste linie,
// 3. sprawdza, czy liczba linii jest parzysta,
// 4. sprawdza, czy każdy wiersz ma dokładnie 106 liczb,
// 5. buduje obiekty typu Grid i zwraca je w wektorze.
std::vector<Grid> f_read_grids_from_file(const std::string& file_name)
{
    std::ifstream file(file_name);
    if (!file)
    {
        throw std::runtime_error("Cannot open file: " + file_name);
    }

    std::vector<std::vector<double>> rows;
    std::string line;

    while (std::getline(file, line))
    {
        const std::vector<double> values = f_parse_line(line);
        if (!values.empty())
        {
            rows.push_back(values);
        }
    }

    // Sprawdzenie, czy plik nie jest pusty.
    if (rows.empty())
    {
        throw std::runtime_error("File is empty: " + file_name);
    }

    // Jedna siatka zajmuje dokładnie dwa wiersze: Y i X.
    if (rows.size() % 2 != 0)
    {
        throw std::runtime_error("File should contain an even number of non-empty lines: " + file_name);
    }

    std::vector<Grid> grids;

    for (std::size_t i = 0; i < rows.size(); i += 2)
    {
        // Każdy wiersz powinien zawierać 6 parametrów i 100 współrzędnych.
        if (rows[i].size() != 106 || rows[i + 1].size() != 106)
        {
            throw std::runtime_error("Each row should contain exactly 106 numbers in file: " + file_name);
        }

        Grid grid;
        grid.y_row = rows[i];
        grid.x_row = rows[i + 1];
        grids.push_back(grid);
    }

    return grids;
}

// Zamienia wektor liczb na jeden napis tekstowy.
// Liczby są łączone spacjami, aby można je było łatwo
// zapisać do pliku wynikowego w czytelnej formie.
std::string f_join_numbers(const std::vector<double>& values)
{
    std::ostringstream output;
    output << std::fixed << std::setprecision(9);

    for (std::size_t i = 0; i < values.size(); ++i)
    {
        if (i > 0)
        {
            output << ' ';
        }
        output << values[i];
    }

    return output.str();
}

// Zapisuje wynik działania programu do pliku tekstowego.
// Do pliku trafiają:
// - nazwa modelu,
// - wartości błędu dla wszystkich siatek,
// - minimalna wartość błędu,
// - wiersz Y najlepiej dopasowanej siatki,
// - wiersz X najlepiej dopasowanej siatki.
void f_write_result_file(
    const std::string& file_name,
    const std::string& model_name,
    const MatchResult& result)
{
    std::ofstream file(file_name);
    if (!file)
    {
        throw std::runtime_error("Cannot create output file: " + file_name);
    }

    file << model_name << "\n";
    file << "MSE values for all grids:\n";
    file << f_join_numbers(result.mse_values) << "\n\n";

    file << std::fixed << std::setprecision(9);
    file << "Minimal MSE: " << result.best_mse << "\n\n";

    file << "Best matching Y row:\n";
    file << f_join_numbers(result.best_grid.y_row) << "\n\n";

    file << "Best matching X row:\n";
    file << f_join_numbers(result.best_grid.x_row) << "\n";
}
