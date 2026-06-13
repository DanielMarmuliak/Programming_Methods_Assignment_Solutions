#pragma once 

#include <vector>
#include "Huffman.h"

// Validates input data before building Huffman tree
void validateInput(const std::vector<SymbolData>& symbols);

// Returns example data for task A
std::vector<SymbolData> getExampleDataA();

// Returns example data for task B
std::vector<SymbolData> getExampleDataB();

// Returns incorrect data to demonstrate exception handling
std::vector<SymbolData> getInvalidNegativeData();

// Returns incorrect data with duplicated symbol
std::vector<SymbolData> getInvalidDuplicateData();

// Returns incorrect data with only one symbol
std::vector<SymbolData> getInvalidTooFewSymbolsData();