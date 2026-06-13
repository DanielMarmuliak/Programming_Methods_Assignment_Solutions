#ifndef ITEM_H
#define ITEM_H

// Represents one item that can be placed in the knapsack
struct Item{
    int id;       
    int profit;   
    int weight;   

    double ratio() const {return static_cast<double>(profit) / weight;}
};

#endif
