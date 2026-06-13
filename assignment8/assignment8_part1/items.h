#ifndef ITEMS_H
#define ITEMS_H

#include <string>

struct Item{
    std::string name;
    int mass;
    int value;

    Item(){
        name = "";
        mass = 0;
        value = 0;
    };
    Item(std::string itemName, int itemMass, int itemValue){
        name = itemName;
        mass = itemMass;
        value = itemValue;
    };
};


#endif 