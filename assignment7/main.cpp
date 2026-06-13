#include <iostream>
#include <vector>

#include "lcg.h"
#include "additive.h"
#include "utils.h"

// Starts the program, handles user input, chooses the generation method and saves results
int main() {
    int choice;
    std::vector<int> numbers;

    std::cout << "Choose generation method:" << std::endl;
    std::cout << "1. Linear Congruential Method" << std::endl;
    std::cout << "2. Additive Congruential Method" << std::endl;
    std::cout << "Your choice: ";
    std::cin >> choice;

    if(choice == 1){
        int n;
        int seed;
        int xmax;

        std::cout << "How many numbers do you want to generate?: ";
        std::cin >> n;

        std::cout << "Enter seed: ";
        std::cin >> seed;

        std::cout << "Enter max value: ";
        std::cin >> xmax;

        numbers = f_generateLCG(n, seed, xmax);

        if(numbers.empty() && n > 0){
            std::cerr << "No numbers were generated." << std::endl;
            return 1;
        }

        f_saveToFile(numbers, "lcg_numbers.txt");

        std::cout << "LCG numbers have been saved to lcg_numbers.txt" << std::endl;
    }
    else if(choice == 2){
        int n;
        int m;
        int seed;

        std::cout << "Enter n: ";
        std::cin >> n;

        std::cout << "Enter modulus m: ";
        std::cin >> m;

        std::cout << "Enter seed for initial LCG table: ";
        std::cin >> seed;

        numbers = f_generateAdditive(n, m, seed);

        if(numbers.empty() && n > 0){
            std::cerr << "No numbers were generated." << std::endl;
            return 1;
        }

        f_saveToFile(numbers, "additive_numbers.txt");

        std::cout << "Additive method numbers have been saved to additive_numbers.txt" << std::endl;
    }
    else {
        std::cerr << "Error: wrong method choice." << std::endl;
        return 1;
    }

    return 0;
}