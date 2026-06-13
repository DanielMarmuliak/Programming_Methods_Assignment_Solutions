#include <iostream>

#include "BackpackSolver.h"
#include "InputOutput.h"

int main(){
    try{
        int numberOfTests = InputOutput::readInteger("number of tests");
        BackpackSolver solver;
        while(numberOfTests--){
            int capacity = InputOutput::readInteger("capacity");
            int numberOfElements = InputOutput::readInteger("number of elements");

            std::vector<int> weights = InputOutput::readWeights(numberOfElements);
            std::vector<int> result;

            bool found = solver.findSolution(capacity, weights, result);

            InputOutput::printResult(capacity, result, found);
        }
    }
    catch (const std::exception& error){
        std::cerr << "Error: " << error.what() << std::endl;
        return 1;
    }
    return 0;
}