#ifndef LCG_H
#define LCG_H

#include <vector>

int f_lcgCalculateM(int xmax);
int f_lcgFindLambda(int a, int m);
int f_lcgCalculateA(int m);
int f_lcgCalculateC(int m);

std::vector<int> f_generateLCG(int n, int seed, int xmax);
std::vector<int> f_generateLCGRaw(int n, int seed, int m);

#endif