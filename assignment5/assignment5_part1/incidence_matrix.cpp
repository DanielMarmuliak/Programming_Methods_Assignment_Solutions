#include "incidence_matrix.h"

// Creates an n x k incidence matrix filled with zeros
std::vector<std::vector<int>> f_createIncMatrix(int n, int k){
    std::vector<std::vector<int>> matrix(n, std::vector<int>(k,0));
    return matrix;
}

// Fills the incidence matrix using the list of directed edges
void f_fillIncMatrix(std::vector<std::vector<int>>& matrix, const std::vector<Edge>& edges){
    // Each edge is one column in the matrix
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].from;
        int v = edges[i].to;

        // Mark start vertex with -1 and end vertex with 1
        matrix[u - 1][i] = -1;
        matrix[v - 1][i] = 1;
    }
}

// Prints the incidence matrix row by row
void f_printMatrix(const std::vector<std::vector<int>>& matrix){
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}