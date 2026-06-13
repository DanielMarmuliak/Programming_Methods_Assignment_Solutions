#include "lcg.h"
#include "utils.h"
#include <iostream>
#include <vector>

// Calculates the modulus value based on the maximum output value
int f_lcgCalculateM(int xmax){
    return xmax + 1;
};

// Finds the period lambda for a given multiplier a and modulus m
int f_lcgFindLambda(int a, int m){
    int value = 1;
    for(int lambda = 1; lambda < m; lambda++){
        value = (value * a) % m;

        if(value == 1){
            return lambda;
        }
    }
    return -1;
};

// Chooses the best multiplier a by finding the value with the maximum period
int f_lcgCalculateA(int m){
    int bestA = 2;
    int bestLambda = 0;
    for (int a = 2; a < m; a++){
        int lambda = f_lcgFindLambda(a, m);
        if (lambda > bestLambda || 
           (lambda == bestLambda && a > bestA)) {
            bestLambda = lambda;
            bestA = a;
        }
    }
    return bestA;
};

// Chooses the largest increment c that is relatively prime to m
int f_lcgCalculateC(int m){
    for(int c = m - 1; c >= 1; c--){
        if(f_findGCD(c, m) == 1){
            return c;
        }
    }
    return 1;
};

// Generates random numbers using the LCG method in the range from 1 to xmax
std::vector<int> f_generateLCG(int n, int seed, int xmax){
    std::vector<int> numbers;

    if(!f_validateN(n)){
        std::cerr << "Error: n must be greater than or equal to 0." << std::endl;
        return numbers;
    }

    if(xmax <= 0){
        std::cerr << "Error: xmax must be greater than 0." << std::endl;
        return numbers;
    }

    int m = f_lcgCalculateM(xmax);
    int a = f_lcgCalculateA(m);
    int c = f_lcgCalculateC(m);

    if(!f_validateM(m)){
        std::cerr << "Error: m must be greater than 0." << std::endl;
        return numbers;
    }

    if(!f_validateValueInRange(a, 0, m)){
        std::cerr << "Error: a must be in range <0, " << m - 1 << ">." << std::endl;
        return numbers;
    }

    if(!f_validateValueInRange(c, 0, m)){
        std::cerr << "Error: c must be in range <0, " << m - 1 << ">." << std::endl;
        return numbers;
    }

    if(!f_validateValueInRange(seed, 0, m)){
        std::cerr << "Error: seed must be in range <0, " << m - 1 << ">." << std::endl;
        return numbers;
    }

    std::cout << "LCG coefficients:" << std::endl;
    std::cout << "m = " << m << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "seed = " << seed << std::endl;

    int x = seed;
    int generated = 0;

    while(generated < n){
        x = (a * x + c) % m;

        if (x != 0) {
            numbers.push_back(x);
            generated++;
        }
    }

    return numbers;
}

// Generates raw LCG values in the range from 0 to m - 1
std::vector<int> f_generateLCGRaw(int n, int seed, int m) {
    std::vector<int> numbers;

    if (!f_validateN(n)) {
        std::cerr << "Error: n must be greater than or equal to 0." << std::endl;
        return numbers;
    }

    if (!f_validateM(m)) {
        std::cerr << "Error: m must be greater than 0." << std::endl;
        return numbers;
    }

    if (!f_validateValueInRange(seed, 0, m)) {
        std::cerr << "Error: seed must be in range <0, " << m - 1 << ">." << std::endl;
        return numbers;
    }

    int a = f_lcgCalculateA(m);
    int c = f_lcgCalculateC(m);

    int x = seed;

    for (int i = 0; i < n; i++) {
        x = (a * x + c) % m;
        numbers.push_back(x);
    }

    return numbers;
}