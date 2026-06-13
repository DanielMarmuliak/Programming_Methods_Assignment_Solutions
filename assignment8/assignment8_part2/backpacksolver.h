#ifndef BACKPACKSOLVER_H
#define BACKPACKSOLVER_H
#include <vector>

class BackpackSolver{
private:
    //Recursive function that checks possible combinations
    bool solveRecursive(int i, 
                          int remainingCapacity,
                          const std::vector<int>& weights,
                          std::vector<int>& result);
public:
    /*
     This function starts the process of searching for a solution

     Returns true if a valid combination was found;
     Returns false if there is no valid combination
    */
    bool findSolution(int capacity, 
                        const std::vector<int>& weights,
                        std::vector<int>& result);                          
};

#endif 