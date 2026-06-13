#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include <vector>

namespace InputOutput
{
    //Reads one integer value from standard input
    int readInteger(const char* valueName);

    //Reads all weights of available elements
    std::vector<int> readWeights(int count);

    //Prints the result of one test case
    void printResult(int capacity,
                     const std::vector<int>& result,
                     bool found);
}

#endif