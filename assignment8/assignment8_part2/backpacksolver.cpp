#include "backpacksolver.h"


bool BackpackSolver::findSolution(int capacity, 
                                  const std::vector<int>& weights,
                                  std::vector<int>& result
){
    result.clear();
    if(capacity <= 0) return false;
    if(weights.empty()) return false;
    return solveRecursive(0, capacity, weights, result);
}


bool BackpackSolver::solveRecursive(int i, 
                                    int remainingCapacity,
                                    const std::vector<int>& weights,
                                    std::vector<int>& result
){
    //1st base case: if remainingCapacity is 0, we found a correct combination
    if(remainingCapacity == 0) return true;

    //2nd base case: if remainingCapacity is negative, the chosen elements are too heavy
    if(remainingCapacity < 0) return false; 

    //3rd base case: if there are no more elements, there is no solution in this branch
    if(i >= static_cast<int>(weights.size())) return false;

    //Trying to take current element
    result.push_back(weights[i]);
    if(solveRecursive(i + 1, remainingCapacity - weights[i], weights, result)) return true;

    //If taking this elemnt didnt work, remove it and try to take second option
    result.pop_back();

    //Skip the current element
    if(solveRecursive(i + 1, remainingCapacity, weights, result)) return true;


    //If neither taking nor skipping worked, this branch does not contain solution
    return false;
}