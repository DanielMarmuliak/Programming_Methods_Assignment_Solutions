#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

int f_findGCD(int a, int b);

bool f_validateN(int n);
bool f_validateM(int m);
bool f_validateValueInRange(int value, int min, int max);

void f_saveToFile(const std::vector<int>& numbers, const std::string& filename);

#endif