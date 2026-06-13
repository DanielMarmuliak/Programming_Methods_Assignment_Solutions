#include "graph.h"
#include <climits>

// Returns the largest vertex number from the edge list
int f_findMaxVertex(const std::vector<Edge>& edges){
    int maxVertex = INT_MIN;

    // Check every edge and find the largest vertex number
    for(int i = 0; i < edges.size(); i++){
        if(maxVertex < edges[i].from)
            maxVertex = edges[i].from;
        
        if(maxVertex < edges[i].to)
            maxVertex = edges[i].to;
    }
    return maxVertex;
}

// Prints otgoing neighbors for each vertex
void f_printNeighbors(const std::vector<Edge>& edges, int n){
    // Go through all vertices
    for(int vertex = 1; vertex <= n; vertex++){
        std::cout << "Neighbors of  " << vertex << ": ";
        
        bool found = false;
        // Find all edges that start from the current vertex
        for(int i = 0; i < edges.size(); i++){
            if(edges[i].from == vertex){
                std::cout << edges[i].to << " ";
                found = true;
            }
        }
        // If no neighbors were found, print None
        if(found == false)
            std::cout << "None";
        std::cout << "\n";

    }
}