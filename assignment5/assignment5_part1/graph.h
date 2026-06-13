#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>

struct Edge
{
    int to;
    int from;
};

int f_findMaxVertex(const std::vector<Edge>& edges);
void f_printNeighbors(const std::vector<Edge>& edges, int n);



#endif