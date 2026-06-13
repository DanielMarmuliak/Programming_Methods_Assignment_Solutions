#include "items.h"
#include "knapsack.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    std::ifstream file("input.txt");
    if(!file){
        std::cout << "Error: Cannot open file" << std::endl;
        return 1;
    }

    int capacity;
    file >> capacity;

    if(capacity <= 0){
        std::cout << "Error: Backpack capacity must be positive" << std::endl;
        return 1;
    }

    std::vector<Item> items;

    std::string name;
    int value;
    int mass;

    while(file >> name >> value >> mass){
        if(mass <= 0){
            std::cout << "Error: Item mass must be positive" << std::endl;
            return 1;
        }
        if(value < 0){
            std::cout << "Error: Item value cannot be negative" << std::endl;
            return 1;
        }

        items.push_back(Item(name, mass, value));
    }

    if(items.empty()){
        std::cout << "Error: No items found in input file" << std::endl;
        return 1;
    }

    Knapsack backpack(capacity, items);

    backpack.printItems();

    backpack.solve();

    backpack.printTableP();
    backpack.printTableQ();
    backpack.printBestValue();

    return 0;
}