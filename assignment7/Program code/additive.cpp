#include "additive.h"
#include "lcg.h"
#include "utils.h"

#include <iostream>
#include <vector>
#include <algorithm>

// Chooses the index pair used in the additive congruential method
std::pair<int, int> f_choosePair(int n){
    if(n == 6){
        return {2, 5};
    }
    return {1, n};
}

// Creates the initial table for the additive method using the raw LCG generator
std::vector<int> f_createInitialTable(int n, int m, int seed) {
    return f_generateLCGRaw(n, seed, m);
}

// Creates a reversed copy of the initial table
std::vector<int> f_reverseTable(const std::vector<int>& x){
    std::vector<int> y = x;
    std::reverse(y.begin(), y.end());
    return y;
}

// Generates random numbers using the additive congruential method
std::vector<int> f_generateAdditive(int n, int m, int seed){
    std::vector<int> numbers;

    if(!f_validateN(n)){
        std::cerr << "Error: n must be greater than or equal to 0." << std::endl;
        return numbers;
    }

    if(!f_validateM(m)){
        std::cerr << "Error: m must be greater than 0." << std::endl;
        return numbers;
    }

    if(n == 0){
        return numbers;
    }

    std::pair<int, int> pair = f_choosePair(n);

    int j = pair.first - 1;
    int k = pair.second - 1;

    if(j < 0 || j >= n || k < 0 || k >= n){
        std::cerr << "Error: chosen pair is not valid for table size n." << std::endl;
        return numbers;
    }

    std::vector<int> x = f_createInitialTable(n, m, seed);
    if(x.size() < n){
        std::cerr << "Error: initial table was not generated correctly." << std::endl;
        return numbers;
    }

    std::vector<int> y = f_reverseTable(x);

    std::cout << "Additive method:" << std::endl;
    std::cout << "n = " << n << std::endl;
    std::cout << "m = " << m << std::endl;
    std::cout << "pair = (" << pair.first << ", " << pair.second << ")" << std::endl;

    for(int i = 0; i < n; i++){
        y[k] = (y[j] + y[k]) % m;
        numbers.push_back(y[k]);
        k--;
        j--;

        if(k < 0){
            k = n - 1;
        }

        if(j < 0){
            j = n - 1;
        }
    }
    return numbers;
}