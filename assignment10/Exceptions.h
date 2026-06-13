#pragma once

#include <stdexcept>
#include <string>

// Exception thrown when input list is empty
class EmptyInputException: public std::runtime_error{
public:
    EmptyInputException()
        : std::runtime_error("The input list is empty") {}
};

// Exception thrown when there are fewer than 2 symbols
class TooFewSymbolsException: public std::runtime_error{
public:
    TooFewSymbolsException()
        : std::runtime_error("To build a Huffman tree, at least two symbols are needed") {}
};

// Exception thrown when frequency or probability is invalid
class InvalidFrequencyException: public std::runtime_error{
public:
    InvalidFrequencyException()
        : std::runtime_error("The frequency or probability must be greater than zero") {}
};

// Eexception thrown then the same symbol appears more than one time 
class DuplicateSymbolException: public std::runtime_error{
public:
    DuplicateSymbolException()
        : std::runtime_error("The same symbol cannot appear more than once") {}
};










