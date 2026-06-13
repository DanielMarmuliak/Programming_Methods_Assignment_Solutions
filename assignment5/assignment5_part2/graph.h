#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include "linked_list.h"

struct Edge {
    int u;
    int v;
};

// Reads all edges from input
bool f_readEdges(std::istream& in, std::vector<Edge>& edges);

// Finds the largest vertex number
int f_findMaxVertex(const std::vector<Edge>& edges);

// Adds one undirected edge to the lists
void f_addEdgeToIncidenceLists(std::vector<LinkedList>& lists, int u, int v);

// Builds all incidence lists
void f_buildIncidenceLists(const std::vector<Edge>& edges, std::vector<LinkedList>& lists);

// Prints all incidence lists
void f_printIncidenceLists(const std::vector<LinkedList>& lists);

// Prints degrees of all vertices.
void f_printDegrees(const std::vector<LinkedList>& lists);

#endif
