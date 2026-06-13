#ifndef KNAPSACK_H
#define KNAPSACK_H
#include "items.h"
#include <vector>
#include <string>

class Knapsack{
private:
    int capacity;
    std::vector<Item> items;

    //Stores the best values for each item set and backpack capacity
    std::vector<std::vector<int>> P;

    //Stores the number of the item chosen in the last step
    std::vector<std::vector<int>> Q;
public:
    Knapsack(int backCap, std::vector<Item> itemList){
        capacity = backCap;
        items = itemList;

        int n = items.size();

        P.resize(n + 1, std::vector<int>(capacity + 1, 0));
        Q.resize(n + 1, std::vector<int>(capacity + 1, 0));
    }

    //Solves the general knapsack problem using dynamic programming
    void solve();

    //Prints all items with their mass and value
    void printItems() const;

    //Prints table P with the best values
    void printTableP() const;

    //Prints table Q with the last chosen items
    void printTableQ() const;

    //Prints the best final value for the full backpack capacity
    void printBestValue() const;


};


#endif