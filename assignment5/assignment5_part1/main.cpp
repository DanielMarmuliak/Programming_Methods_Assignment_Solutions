#include "incidence_matrix.h"
#include "graph.h"
#include <iostream>
#include <fstream>
#include <vector>

// Main function: reads graph data, builds the matrix, and prints results
int main(){
    int k;
    std::cin >> k;

    std::vector<Edge> edges;

    // Read all edges
    for(int i = 0; i < k; i++){
        Edge e;
        std::cin >> e.from >> e.to;
        edges.push_back(e);
    }

    // Find number of vertices
    int n = f_findMaxVertex(edges);
    std::vector<std::vector<int>> matrix = f_createIncMatrix(n,k);
    f_fillIncMatrix(matrix, edges);

    // Print results
    std::cout << "INcidance matrix:\n";
    f_printMatrix(matrix);

    std::cout << "\nNeighbors:\n";
    f_printNeighbors(edges, n);

    return 0;
}