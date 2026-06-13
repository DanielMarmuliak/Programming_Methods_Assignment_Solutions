# Laboratory 3 – Programming Methods

## Task Description

The aim of the task was to write a program that operates on an integer array sorted in non-decreasing order. For each data set, the program performs three operations:

1. **Counting the number of occurrences of a given value**
   This was implemented with pessimistic time complexity O(log n) using two binary searches:

   * the first element `>= x`
   * the first element `> x`

2. **Searching for the index of an element equal to a given value using interpolation search**
   The classic interpolation search algorithm was used.
   If the value does not occur in the array, `-1` is returned.

3. **Removing duplicates**
   Duplicates are removed in place, without creating an additional helper array, in O(n) time.

## Program Structure

The program was divided into the following files:

* `main.cpp` – input/output handling
* `algorithms.h` – function declarations
* `algorithms.cpp` – implementation of the algorithms

## Used Functions

* `f_findFirstNotLess(...)`
* `f_findFirstGreater(...)`
* `f_countOccurrences(...)`
* `f_interpolationSearch(...)`
* `f_removeDuplicates(...)`

## Notes

* The input array is sorted in non-decreasing order.
* If the same value occurs multiple times, interpolation search may return **any valid index** of one of these occurrences.
* After removing duplicates, at most the first 200 elements are printed, with 50 elements per line.

## Compilation

```bash
g++ -std=c++17 -O2 main.cpp algorithms.cpp -o lab3
```
