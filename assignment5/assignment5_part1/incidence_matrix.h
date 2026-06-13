#ifndef INCIDANCE_MATRIX_H
#define INCIDANCE_MATRIX_H

#include "graph.h"
#include <vector>
#include <iostream>

std::vector<std::vector<int>> f_createIncMatrix(int n, int k);
void f_fillIncMatrix(std::vector<std::vector<int>>& matrix, const std::vector<Edge>& edges);
void f_printMatrix(const std::vector<std::vector<int>>& matrix);




#endif