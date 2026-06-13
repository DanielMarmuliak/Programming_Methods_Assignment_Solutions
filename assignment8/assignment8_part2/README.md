# Knapsack Problem — Recursive Solution

## Program Description

The program searches for a set of elements whose total weight is exactly equal to the backpack capacity.

If the program finds a solution, it prints the selected elements.

If there is no solution, it prints:

```text
BRAK
```

---

## Project Structure

The project consists of the following files:

```text
main.cpp
BackpackSolver.h
BackpackSolver.cpp
InputOutput.h
InputOutput.cpp
```

---

## How Does the Program Work?

For each element, the program checks two possibilities:

```text
1. take the element
2. skip the element
```

It does this recursively, which means that the function calls itself for the next elements.

If the sum of the selected elements equals the backpack capacity, the program stops searching and prints the result.

---

## File Description

### `main.cpp`

This is the main program file.

It is responsible for:

* reading the number of tests,
* reading the data for each test,
* starting the algorithm,
* printing the result,
* handling errors.

---

### `BackpackSolver.h`

This file contains the declaration of the `BackpackSolver` class.

This class contains functions responsible for solving the knapsack problem.

```cpp
findSolution(...)
solveRecursive(...)
```

---

### `BackpackSolver.cpp`

This file contains the actual algorithm.

The function:

```cpp
findSolution(...)
```

prepares the data and starts the recursion.

The function:

```cpp
solveRecursive(...)
```

checks possible combinations of elements.

The most important conditions are:

```cpp
if (remainingCapacity == 0)
    return true;
```

This means that a correct solution has been found.

```cpp
if (remainingCapacity < 0)
    return false;
```

This means that the sum of the elements is too large.

```cpp
if (index >= weights.size())
    return false;
```

This means that there are no more elements and no solution has been found.

---

### `InputOutput.h`

This file contains declarations of functions for reading and printing data.

---

### `InputOutput.cpp`

This file contains the functions:

```cpp
readInteger(...)
```

Reads one number.

```cpp
readWeights(...)
```

Reads the list of element weights.

```cpp
printResult(...)
```

Prints the program result.

Example result:

```text
20 = 8 7 5
```

or:

```text
BRAK
```

---

## Test Example

### Input Data

```text
3
20
5
11 8 7 6 5
21
3
5 6 7
20
5
11 7 6 8 5
```

### Expected Output

```text
20 = 8 7 5
BRAK
20 = 7 8 5
```

---

## How to Compile the Program?

```bash
g++ main.cpp BackpackSolver.cpp InputOutput.cpp -o backpack.exe
backpack.exe
```

---

## Summary

The program uses recursion to check different combinations of elements.

For each element, the program decides whether to take it or skip it.
