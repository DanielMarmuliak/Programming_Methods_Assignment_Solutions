#include "knapsack.h"
#include <iostream>
#include <iomanip>

void Knapsack::solve(){
    int n = items.size();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= capacity; j++){
            int currMass = items[i - 1].mass;
            int currVal = items[i - 1].value;

            int optionWithoutItem = P[i - 1][j];
            if(currMass <= j){
                int optionWithItem = P[i][j - currMass] + currVal;
                if(optionWithItem > optionWithoutItem){
                    P[i][j] = optionWithItem;
                    Q[i][j] = i;
                }else{
                    P[i][j] = optionWithoutItem;
                    Q[i][j] = Q[i - 1][j];
                }
            }
            else{
                P[i][j] = P[i - 1][j];
                Q[i][j] = Q[i - 1][j];
            }
        }
    }
}

void Knapsack::printItems() const {
    std::cout << "Items:\n";
    for(int i = 0; i < items.size(); i++){
        std::cout << i + 1 << ". "
                  << items[i].name
                  << " | mass: " << items[i].mass
                  << " | value: " << items[i].value
                  << "\n";
    }
}


void Knapsack::printTableP() const {
    std::cout << "\nTable P - best values:\n\n";
    std::cout << std::setw(5) << "i/j";

    for(int j = 0; j <= capacity; j++){
        std::cout << std::setw(5) << j;
    }

    std::cout << "\n";

    for(int i = 0; i < P.size(); i++){
        std::cout << std::setw(5) << i;

        for(int j = 0; j < P[i].size(); j++){
            std::cout << std::setw(5) << P[i][j];
        }
        std::cout << "\n";
    }
}

void Knapsack::printTableQ() const {
    std::cout << "\nTable Q - last chosen item:\n\n";
    std::cout << std::setw(5) << "i/j";
    for(int j = 0; j <= capacity; j++){
        std::cout << std::setw(5) << j;
    }

    std::cout << "\n";

    for(int i = 0; i < Q.size(); i++){
        std::cout << std::setw(5) << i;

        for (int j = 0; j < Q[i].size(); j++) {
            std::cout << std::setw(5) << Q[i][j];
        }
        std::cout << "\n";
    }
}

void Knapsack::printBestValue() const {
    int n = items.size();
    std::cout << "\nBest value: " << P[n][capacity] << "\n";
}