#include "InputOutput.h"

#include <iostream>
#include <stdexcept>

int InputOutput::readInteger(const char* valueName){
    int value;

    if(!(std::cin >> value))
        throw std::runtime_error("Invalid input while reading value");
    
    if(value < 0)
        throw std::runtime_error("Negative value is not allowed");

    return value;
}

std::vector<int> InputOutput::readWeights(int count){
    if(count <= 0)
        throw std::runtime_error("Number of elements must be greater than 0");
    
    std::vector<int> weights;
    for(int i = 0; i < count; i++){
        int weight = readInteger("weight");
        if(weight <= 0)
            throw std::runtime_error("Weight must be greater than 0.");
    
        weights.push_back(weight);
    }
    return weights;
}

void InputOutput::printResult(
    int capacity,
    const std::vector<int>& result,
    bool found
){
    if(!found){
        std::cout << "BRAK" << std::endl;
        return;
    }
    std::cout << capacity << " = ";

    for(int i = 0; i < static_cast<int>(result.size()); i++){
        std::cout << result[i];

        if(i < static_cast<int>(result.size()) - 1)
            std::cout << " ";    
    }
    std::cout << std::endl;
}