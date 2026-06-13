#include "utils.h"
#include <fstream>
#include <iostream>

// Calculates the greatest common divisor using the Euclidean algorithm
int f_findGCD(int a, int b){
    if(a == 0)
        return b;
    return f_findGCD(b % a, a);
}

// Checks if the number of values to generate is valid
bool f_validateN(int n){
    return n >= 0;
}

// Checks if the modulus value is valid
bool f_validateM(int m){
    return m > 0;
}

// Checks if a value is inside the given range
bool f_validateValueInRange(int value, int min, int max){
    return value >= min && value < max;
}

// Saves generated numbers to a text file
void f_saveToFile(const std::vector<int>& numbers, const std::string& filename){
    std::ofstream file(filename);

    if(!file){
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    for(int number : numbers){
        file << number << std::endl;
    }

    file.close();
}