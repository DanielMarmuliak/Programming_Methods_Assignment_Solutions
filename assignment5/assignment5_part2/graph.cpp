#include "graph.h"
#include <climits>

bool f_readEdges(std::istream& in, std::vector<Edge>& edges){
    int k;
    in >> k;

    if(!in || k < 0) {
        return false;
    }
    edges.clear();
    for(int i = 0; i < k; i++){
        Edge edge;
        in >> edge.u >> edge.v;
        if(!in || edge.u <= 0 || edge.v <= 0){
            return false;
        }
        edges.push_back(edge);
    }

    return true;
}

int f_findMaxVertex(const std::vector<Edge>& edges){
    int maxVertex = INT_MIN;
    for(int i = 0; i < edges.size(); i++){
        if(edges[i].u > maxVertex){
            maxVertex = edges[i].u;
        }
        if(edges[i].v > maxVertex){
            maxVertex = edges[i].v;
        }
    }
    return maxVertex;
}

void f_addEdgeToIncidenceLists(std::vector<LinkedList>& lists, int u, int v){
    lists[u].f_pushBack(v);

    if(u == v){
        lists[u].f_pushBack(v);
    }else {
        lists[v].f_pushBack(u);
    }
}

void f_buildIncidenceLists(const std::vector<Edge>& edges, std::vector<LinkedList>& lists){
    for(int i = 0; i < edges.size(); i++){
        f_addEdgeToIncidenceLists(lists, edges[i].u, edges[i].v);
    }
}

void f_printIncidenceLists(const std::vector<LinkedList>& lists){
    std::cout << "Incidence List:" << std::endl;
    for(int i = 1; i < lists.size(); i++){
        std::cout << i << ": ";
        lists[i].f_print();
        std::cout << "\n";
    }
}

void f_printDegrees(const std::vector<LinkedList>& lists){
    std::cout << "\nVertices degrees:" << std::endl;
    for(int i = 1; i < lists.size(); i++) {
        std::cout << "deg(" << i << ") = " << lists[i].f_size() << std::endl;
    }
}
