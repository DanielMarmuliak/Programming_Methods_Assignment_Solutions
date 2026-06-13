#ifndef KNAPSACK_SOLVER_H
#define KNAPSACK_SOLVER_H

#include "Item.h"
#include <fstream>
#include <string>
#include <vector>

// Solves the 0/1 knapsack problem using backtracking with branch and bound.
class KnapsackSolver{
public:
    KnapsackSolver(std::vector<Item> items, int capacity);

    // Starts the algorithm and writes all steps to the selected text file.
    void solve(const std::string& outputFileName);

private:
    std::vector<Item> items;
    int capacity;
    int bestProfit;
    int bestWeight;
    std::vector<int> currentChoice;
    std::vector<int> bestChoice;
    std::ofstream output;
    int nodeCounter;

    // Sorts items by descending profit-to-weight ratio
    void sortItemsByRatio();

    // Calculates the upper bound for the current node using the fractional knapsack idea
    double calculateBound(int level, int currentProfit, int currentWeight) const;

    // Checks if a node can still lead to a better solution
    bool isPromising(int currentWeight, double bound) const;

    // Recursively checks the search tree: take or skip the next item
    void backtrack(int level, int currentProfit, int currentWeight);

    // Saves the current solution if it is better than the best one found so far
    void updateBestSolution(int currentProfit, int currentWeight);

    // Writes the final result to the output file
    void writeFinalResult();

    // Converts a selected/not selected vector into a readable text description
    std::string choiceToText(const std::vector<int>& choice) const;

    // Writes a separator line to make the output file easier to read
    void writeSeparator();
};

#endif
