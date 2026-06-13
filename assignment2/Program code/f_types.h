#ifndef F_TYPES_H
#define F_TYPES_H

#include <string>
#include <vector>

// Reprezentuje jedną siatkę zapisaną w pliku.
// y_row - cały wiersz Y (6 parametrów + 100 współrzędnych Y)
// x_row - cały wiersz X (6 parametrów + 100 współrzędnych X)
struct Grid
{
    std::vector<double> y_row;
    std::vector<double> x_row;
};

// Zawiera wynik porównania siatki nieznanej
// ze wszystkimi siatkami wzorcowymi.
struct MatchResult
{
    std::vector<double> mse_values;
    int best_index = -1;
    double best_mse = 0.0;
    Grid best_grid;
};

#endif
