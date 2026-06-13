#include "Item.h"
#include "KnapsackSolver.h"
#include <vector>

std::vector<Item> createItems(){
    return {
        {1, 20, 2},
        {2, 30, 5},
        {3, 35, 7},
        {4, 12, 3},
        {5, 3, 1}
    };
}


int main(){
    const int capacity = 19;
    std::vector<Item> items = createItems();

    KnapsackSolver solver(items, capacity);
    solver.solve("wynik.txt");

    return 0;
}
