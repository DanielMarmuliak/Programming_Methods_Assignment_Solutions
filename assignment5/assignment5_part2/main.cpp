#include <iostream>
#include <vector>
#include "graph.h"

int main() {
    std::vector<Edge> edges;

    if (!f_readEdges(std::cin, edges)) {
        std::cout << "Input data error" << std::endl;
        return 1;
    }

    int maxVertex = f_findMaxVertex(edges);

    if (maxVertex == 0) {
        std::cout << "Graph is emty" << std::endl;
        return 0;
    }

    std::vector<LinkedList> incidenceLists(maxVertex + 1);

    f_buildIncidenceLists(edges, incidenceLists);
    f_printIncidenceLists(incidenceLists);
    f_printDegrees(incidenceLists);

    return 0;
}