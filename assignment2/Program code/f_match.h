#ifndef F_MATCH_H
#define F_MATCH_H

#include "f_types.h"
#include <vector>

// Oblicza błąd dopasowania pomiędzy siatką nieznaną
// a jedną siatką wzorcową.
double f_compute_mse(const Grid& unknown_grid, const Grid& candidate_grid);

// Przeszukuje wszystkie siatki wzorcowe i zwraca
// najlepiej dopasowaną siatkę wraz z dodatkowymi danymi.
MatchResult f_find_best_match(const Grid& unknown_grid, const std::vector<Grid>& candidate_grids);

#endif
