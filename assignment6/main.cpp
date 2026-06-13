#include <iostream>
#include "search.h"
#include <vector>

// Reads input data, calls all four search functions,
// and prints the results in the required format
int main(){
    int numberOfTests; 
    std::cin >> numberOfTests;
    for(int i = 0; i < numberOfTests; i++){
        int n, m;
        std::cin >> n >> m;

        std::vector<std::vector<int>> matrix (n, std::vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                std::cin >> matrix[i][j];
            }
        }
        int k;
        std::cin >> k;

        Result r1 = f_iterativeFirst(matrix, n, m, k);
        Result r2 = f_iterativeLast(matrix, n, m, k);
        Result r3 = f_recursiveFirst(matrix, n, m, k);
        Result r4 = f_recursiveLast(matrix, n, m, k);

        if (r1.found) {
            std::cout << "IterFirst: " << k << " in (" << r1.row << "," << r1.column << ")" << std::endl;
        } else {
            std::cout << "IterFirst: " << k << " not found." << std::endl;
        }

        if (r2.found) {
            std::cout << "IterLast: " << k << " in (" << r2.row << "," << r2.column << ")" << std::endl;
        } else {
            std::cout << "IterLast: " << k << " not found." << std::endl;
        }
        
        if(r3.found){
        std::cout << "RecFirst: " << k << " in (" << r3.row << "," << r3.column << ")" << std::endl;
        }
        else{
        std::cout << "RecFirst: " << k << " not found." << std::endl;
        }

        if(r4.found){
        std::cout << "RecLast: " << k << " in (" << r4.row << "," << r4.column << ")" << std::endl;
        }
        else{
        std::cout << "RecLast: " << k << " not found." << std::endl;
        }    
    }
    return 0;
}