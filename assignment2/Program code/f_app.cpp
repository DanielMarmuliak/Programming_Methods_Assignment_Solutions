#include "f_app.h"

#include "f_io.h"
#include "f_match.h"

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

// Główna funkcja sterująca działaniem programu.
// Pobiera od użytkownika:
// - nazwę modelu,
// - nazwę pliku z siatkami wzorcowymi,
// - nazwę pliku z siatką nieznaną,
// - nazwę pliku wynikowego.
// Następnie:
// 1. odczytuje dane z plików,
// 2. sprawdza poprawność danych,
// 3. wyszukuje najlepiej dopasowaną siatkę,
// 4. zapisuje wynik do pliku,
// 5. wyświetla podsumowanie na ekranie.
void f_run()
{
    std::string model_name;
    std::string grid_file_name;
    std::string unknown_file_name;
    std::string output_file_name;

    std::cout << "Model name: ";
    std::getline(std::cin, model_name);

    std::cout << "Grid file name: ";
    std::getline(std::cin, grid_file_name);

    std::cout << "Unknown model file name: ";
    std::getline(std::cin, unknown_file_name);

    std::cout << "Output file name: ";
    std::getline(std::cin, output_file_name);

    // Odczyt wszystkich siatek wzorcowych z pliku.
    const std::vector<Grid> candidate_grids = f_read_grids_from_file(grid_file_name);

    // Odczyt siatki nieznanej z pliku.    
    const std::vector<Grid> unknown_grids = f_read_grids_from_file(unknown_file_name);

    // W pliku z siatką nieznaną powinna znajdować się dokładnie jedna siatka.
    if (unknown_grids.size() != 1)
    {
        throw std::runtime_error("Unknown model file should contain exactly one grid.");
    }

    // Wyznaczenie najlepszego dopasowania.
    const MatchResult result = f_find_best_match(unknown_grids[0], candidate_grids);

    // Zapis wyniku do pliku tekstowego.
    f_write_result_file(output_file_name, model_name, result);

    // Wyświetlenie najważniejszych informacji na ekranie.
    std::cout << "\nDone.\n";
    std::cout << "Best grid index (from 1): " << result.best_index + 1 << "\n";
    std::cout << "Minimal MSE: " << result.best_mse << "\n";
    std::cout << "Result saved to: " << output_file_name << "\n";
}
