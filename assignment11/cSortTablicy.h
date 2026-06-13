#ifndef CSORTTABLICY_H
#define CSORTTABLICY_H

#include "cTablica.h"

#include <string>
#include <vector>

class cSortTablicy{
private:
    cTablica tablica;

    // Reads an integer from the keyboard
    int readInt(const std::string& message) const;

    // Generates an array of the selected type
    std::vector<int> generateArray(int n, int type) const;

    // Runs the selected sorting method
    SortStats sortByMethod(cTablica& temp, int method) const;

    // Returns the name of the sorting method
    std::string methodName(int method) const;

    // Returns the name of the array type
    std::string typeName(int type) const;

    // Prints sorting statistics
    void printStats(const SortStats& stats) const;

public:
    // Starts the main program menu
    void menu();

    // Reads the array from the keyboard
    void inputFromKeyboard();

    // Generates the array based on user choice
    void generateFromKeyboard();

    // Sorts the current array using the selected method
    void sortCurrentArray();

    // Runs benchmark tests and saves the results to a file
    void runBenchmark(const std::string& fileName);
};

#endif