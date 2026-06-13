# Task: Pseudorandom Number Generator

## Task Description

The program generates pseudorandom numbers using two methods:

1. **Linear Congruential Method — LCG**
2. **Additive Congruential Method**

After starting the program, the user selects the number generation method, enters the required input data, and then the program saves the generated sequence of numbers to a text file in the form of one column.

---

## File Structure

* `main.cpp` – starts the program, handles method selection and input data
* `lcg.h` – declarations of functions related to the linear congruential method
* `lcg.cpp` – definitions of functions related to the linear congruential method
* `additive.h` – declarations of functions related to the additive congruential method
* `additive.cpp` – definitions of functions related to the additive congruential method
* `utils.h` – declarations of helper functions
* `utils.cpp` – definitions of helper functions

---

## How the Program Works

### 1. Method Selection

After starting the program, the user chooses one of two methods:

```text
1. Linear Congruential Method
2. Additive Congruential Method
```

For option `1`, the program starts a generator based on the **linear congruential method**.

For option `2`, the program starts a generator based on the **additive congruential method**.

---

# Linear Congruential Method — LCG

## Method Description

The linear congruential method generates consecutive pseudorandom numbers using the formula:

```text
X(n+1) = (a * X(n) + c) mod m
```

where:

* `X(n)` – the previous pseudorandom number,
* `X(n+1)` – the next pseudorandom number,
* `a` – multiplier,
* `c` – increment,
* `m` – modulus,
* `seed` / `x0` – initial value of the generator.

The LCG generator is deterministic, which means that for the same values of `seed`, `a`, `c`, and `m`, it will always generate the same sequence of numbers.

---

## Input Data for LCG

The program reads:

* `n` – the number of values to generate,
* `seed` – the initial value of the generator,
* `xmax` – the maximum pseudorandom value.

Example:

```text
How many numbers do you want to generate?: 6
Enter seed: 5
Enter max value: 12
```

For `xmax = 12`, the program generates numbers from the range:

```text
<1, 12>
```

---

## Assumptions for LCG

The program checks the following conditions:

```text
n >= 0
m > 0
0 <= a < m
0 <= c < m
0 <= x0 < m
```

where:

* `n` – number of generated values,
* `m` – modulus,
* `a` – multiplier,
* `c` – increment,
* `x0` – initial generator value, also called `seed`.

---

## Selection of LCG Coefficients

The generator coefficients are calculated automatically based on the value of `xmax`.

### Calculating `m`

The function:

```cpp
int f_lcgCalculateM(int xmax);
```

calculates the modulus using the formula:

```text
m = xmax + 1
```

Thanks to this, the generator internally works on values from the range:

```text
0 ... 12
```

Since the final result should belong to the range `<1, xmax>`, the value `0` is skipped when saving the results.

---

### Calculating `a`

The function:

```cpp
int f_lcgCalculateA(int m);
```

is responsible for selecting the multiplier `a`.

The program checks consecutive values of `a` from the range:

```text
2 <= a < m
```

For each value of `a`, the period `lambda` is calculated.

The period is determined by the function:

```cpp
int f_lcgFindLambda(int a, int m);
```

The function searches for the smallest value of `lambda` for which the following condition is satisfied:

```text
a^lambda mod m = 1
```

The program chooses the value of `a` for which the period `lambda` is the largest.

If several values of `a` have the same maximum period, the largest value of `a` is chosen.

Example for:

```text
xmax = 12
m = 13
```

the program may choose:

```text
a = 11
```

---

### Calculating `c`

The function:

```cpp
int f_lcgCalculateC(int m);
```

is responsible for selecting the increment `c`.

The program chooses the largest value of `c` that satisfies the condition:

```text
GCD(c, m) = 1
```

The greatest common divisor is calculated using the function:

```cpp
int f_findGCD(int a, int b);
```

The `f_findGCD` function uses the Euclidean algorithm.

Example:

```text
m = 13
c = 12
```

The numbers `12` and `13` are relatively prime, so `c = 12` can be used as the increment.

---

## LCG Generating Function

The function responsible for generating a sequence of numbers using the LCG method is:

```cpp
std::vector<int> f_generateLCG(int n, int seed, int xmax);
```

The function performs the following steps:

1. Creates an empty vector for the generated numbers.
2. Checks the correctness of the input data.
3. Calculates the coefficients `m`, `a`, and `c`.
4. Checks whether `seed`, `a`, and `c` are in the correct range.
5. Sets the initial value:

```text
x = seed
```

6. Generates consecutive values using the formula:

```text
x = (a * x + c) mod m
```

7. Skips the value `0` so that the result belongs to the range `<1, xmax>`.
8. Adds the generated numbers to the vector.
9. Returns the vector with the results.

---

## Helper LCG Function

The program also contains the function:

```cpp
std::vector<int> f_generateLCGRaw(int n, int seed, int m);
```

This is a helper version of the LCG generator.

It differs from `f_generateLCG` because it does not skip the value `0`.

It generates numbers from the range:

```text
0 <= x < m
```

This function is used in the additive congruential method to create the initial table of values.

---

# Additive Congruential Method

## Method Description

The additive congruential method generates numbers based on a previously prepared table of values.

The next number is created by adding two table elements and performing the modulo operation.

Basic formula:

```text
Y[k] = (Y[j] + Y[k]) mod m
```

where:

* `Y` – generator value table,
* `j` – first index,
* `k` – second index,
* `m` – modulus.

After calculating the new value, the cell `Y[k]` is updated.

Then the indices `j` and `k` are decreased. If any index drops below zero, it is moved to the end of the table.

---

## Input Data for the Additive Method

The program reads:

* `n` – the number of values to generate and the size of the initial table,
* `m` – modulus,
* `seed` – initial value for the helper LCG generator.

Example:

```text
Enter n: 6
Enter modulus m: 8
Enter seed for initial LCG table: 5
```

---

## Assumptions for the Additive Method

The program checks the following conditions:

```text
n > 0
m > 0
0 <= seed < m
```

---

## Selecting the Index Pair `(j, k)`

In the additive method, a pair of indices `(j, k)` is required.

In the laboratory example for:

```text
n = 6
m = 8
```

the selected pair is:

```text
(2, 5)
```

In the program, the function responsible for selecting the pair is:

```cpp
std::pair<int, int> choosePair(int n);
```

For `n = 6`, the function returns:

```text
(2, 5)
```

Since in the laboratory example the table is indexed from `1`, and in C++ arrays are indexed from `0`, the program converts the indices as follows:

```text
j = 2 - 1 = 1
k = 5 - 1 = 4
```

---

## Creating the Initial Table

The additive congruential method requires an initial table of values.

In the program, this table is generated using the previously implemented LCG generator.

The function responsible for this is:

```cpp
std::vector<int> createInitialTable(int n, int m, int seed);
```

The function calls:

```cpp
f_generateLCGRaw(n, seed, m);
```

As a result, an initial table containing values from the range is created:

```text
0 <= x < m
```

---

## Reversing the Table

According to the laboratory example, after generating the initial table `X`, a table `Y` is created as the reversed version of table `X`.

Example:

```text
X = [2, 5, 1, 7, 4, 3]
Y = [3, 4, 7, 1, 5, 2]
```

The function responsible for reversing the table is:

```cpp
std::vector<int> reverseTable(const std::vector<int>& x);
```

The implementation uses the function:

```cpp
std::reverse(y.begin(), y.end());
```

---

## Additive Method Generating Function

The function responsible for generating a sequence of numbers using the additive method is:

```cpp
std::vector<int> f_generateAdditive(int n, int m, int seed);
```

The function performs the following steps:

1. Creates an empty vector for the generated numbers.
2. Checks the correctness of the input data.
3. Selects the index pair `(j, k)`.
4. Converts the indices from 1-based notation to 0-based C++ indices.
5. Creates the initial table `X` using LCG.
6. Reverses table `X`, creating table `Y`.
7. Generates consecutive numbers using the formula:

```text
Y[k] = (Y[j] + Y[k]) mod m
```

8. Adds the value `Y[k]` to the result vector.
9. Decreases the indices `j` and `k`.
10. If an index drops below `0`, it is set to the end of the table.
11. Returns the vector with the generated numbers.

---

## Example of the Additive Method

For the data:

```text
n = 6
m = 8
pair = (2, 5)
```

after converting to C++ indexing:

```text
j = 1
k = 4
```

If table `Y` has the form:

```text
Y = [3, 4, 7, 1, 5, 2]
```

then the first step looks as follows:

```text
Y[k] = (Y[j] + Y[k]) mod m
Y[4] = (Y[1] + Y[4]) mod 8
Y[4] = (4 + 5) mod 8
Y[4] = 1
```

After the update, the table looks like this:

```text
Y = [3, 4, 7, 1, 1, 2]
```

Then the indices are decreased:

```text
j = j - 1
k = k - 1
```

---

# Helper Functions

## `f_findGCD`

```cpp
int f_findGCD(int a, int b);
```

This function calculates the greatest common divisor of two numbers using the Euclidean algorithm.

It is used when selecting the coefficient `c` in the LCG method.

---

## `f_validateN`

```cpp
bool f_validateN(int n);
```

This function checks whether the number of generated values is correct.

Condition for LCG:

```text
n >= 0
```

For the additive method, the following is additionally required:

```text
n > 0
```

because `n` determines the size of the initial table.

---

## `f_validateM`

```cpp
bool f_validateM(int m);
```

This function checks whether the modulus is valid.

Condition:

```text
m > 0
```

---

## `f_validateValueInRange`

```cpp
bool f_validateValueInRange(int value, int min, int max);
```

This function checks whether a given value is within a specified range.

In the program, it is used, among other things, to check:

```text
0 <= seed < m
0 <= a < m
0 <= c < m
```

---

## `f_saveToFile`

```cpp
void f_saveToFile(const std::vector<int>& numbers, const std::string& filename);
```

This function saves the generated sequence of numbers to a text file.

Each number is saved in a separate line, which means the output is written as one column.

Example file content:

```text
7
7
7
1
4
1
```

---

# Implementation Approach

The program was implemented modularly.

This means that each part of the program is responsible for a separate part of its operation:

```text
main.cpp       - menu handling and communication with the user
lcg.cpp        - implementation of the linear congruential method
additive.cpp   - implementation of the additive congruential method
utils.cpp      - helper functions
```

Thanks to this, the code is more readable, easier to test, and easier to expand.

---

## Use of Vector

The generated numbers are stored in the object:

```cpp
std::vector<int> numbers;
```

Each new number is added to the vector using:

```cpp
numbers.push_back(value);
```

Thanks to this, the functions that generate numbers do not save them directly to a file.

First, they return a ready vector of results, and only later does the helper function save this vector to a file.

This solution separates generation logic from data-saving logic.

---

# Compilation

Run the following command in the folder containing the files:

```bash
g++ main.cpp lcg.cpp additive.cpp utils.cpp -o program.exe
```

---

# Running the Program

In PowerShell, the program can be started with the command:

```bash
.\program.exe
```

In a Linux terminal or Git Bash:

```bash
./program.exe
```

---

# Example Usage

## Linear Congruential Method

Sample input data:

```text
Choose generation method:
1

How many numbers do you want to generate?:
6

Enter seed:
5

Enter max value:
12
```

The program calculates the coefficients `m`, `a`, and `c`, generates numbers from the range:

```text
1 ... 12
```

and saves the result to the file:

```text
lcg_numbers.txt
```

---

## Additive Congruential Method

Sample input data:

```text
Choose generation method:
2

Enter n:
6

Enter modulus m:
8

Enter seed for initial LCG table:
5
```

The program creates the initial table using LCG, reverses it, selects the pair `(2, 5)`, and then generates numbers using the additive congruential method.

The result is saved to the file:

```text
additive_numbers.txt
```

---

# Output Files

Depending on the selected method, the program saves data to one of the following files:

```text
lcg_numbers.txt
additive_numbers.txt
```

Each number is placed in a separate line.

---

# Summary

The program implements two methods of generating pseudorandom numbers:

1. **Linear congruential method**, where each next value depends on the previous value and the coefficients `a`, `c`, and `m`.
2. **Additive congruential method**, where consecutive values are created based on two elements stored in a table.

Dividing the program into separate files helps keep the code readable and makes future project development easier.
