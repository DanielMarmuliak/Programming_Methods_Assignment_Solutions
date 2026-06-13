#include "InputData.h"
#include "Exceptions.h"

#include <set>

void validateInput(const std::vector<SymbolData>& symbols){
    if(symbols.empty()) throw EmptyInputException();

    if(symbols.size() < 2) throw TooFewSymbolsException();

    std::set<char> usedSymbols;
    for(const SymbolData& item: symbols){
        if(item.frequency <= 0) throw InvalidFrequencyException();

        if(usedSymbols.count(item.symbol) > 0) throw DuplicateSymbolException();

        usedSymbols.insert(item.symbol);
    }
}

std::vector<SymbolData> getExampleDataA(){
    return {
        {'A', 12},
        {'B', 7},
        {'I', 18},
        {'M', 10},
        {'S', 9},
        {'X', 5},
        {'Z', 2}
    };
}

std::vector<SymbolData> getExampleDataB(){
    return {
        {'c', 0.11},
        {'e', 0.22},
        {'i', 0.16},
        {'r', 0.12},
        {'s', 0.15},
        {'t', 0.10},
        {'x', 0.14}
    };
}

std::vector<SymbolData> getInvalidNegativeData(){
    return {
        {'A', 12},
        {'B', -7},
        {'C', 5}
    };
}

std::vector<SymbolData> getInvalidDuplicateData(){
    return {
        {'A', 12},
        {'B', 7},
        {'A', 5}
    };
}

std::vector<SymbolData> getInvalidTooFewSymbolsData(){
    return {
        {'A', 12}
    };
}