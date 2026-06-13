# Project: Comparison of Array Sorting Methods

## Project Objective

The objective of the project was to write a C++ program that makes it possible to compare selected sorting algorithms in terms of the number of comparisons and element swaps performed.

The following sorting methods were implemented in the program:

1. **Shaker sort** — bidirectional bubble sort.
2. **Quick sort with Lomuto partitioning**.
3. **Quick sort with Hoare partitioning**.
4. **Heap sort**.

The program allows the user to check how the algorithms work for arrays of different lengths and different types of data ordering.

---

## Project Structure

The project was divided into several files to make the code more readable and easier to develop.

```text
ProjektSortowanie/
│
├── main.cpp
├── SortStats.h
├── cTablica.h
├── cTablica.cpp
├── cSortTablicy.h
└── cSortTablicy.cpp
```

### File Description

#### `main.cpp`

This file contains the main function of the program. An object of the `cSortTablicy` class is created here, and then the program menu is started.

#### `SortStats.h`

This file contains the `SortStats` structure, which stores sorting statistics:

* number of comparisons,
* number of swaps.

#### `cTablica.h`

The header file of the `cTablica` class. This class stores the array and the declarations of sorting methods.

#### `cTablica.cpp`

This file contains implementations of the sorting algorithms:

* `shakerSort()`,
* `quickSortLomuto()`,
* `quickSortHoare()`,
* `heapSort()`.

It also contains helper functions such as `partitionLomuto()`, `partitionHoare()`, `heapify()`, and `swapElements()`.

#### `cSortTablicy.h`

The header file of the `cSortTablicy` class. This class is responsible for user interaction, the program menu, generating arrays, and running tests.

#### `cSortTablicy.cpp`

This file contains the implementation of the program menu, array generation, sorting method selection, and saving results to a text file.

---

## Program Description

The program works in console mode. After starting, the following menu is displayed:

```text
===== MENU =====
1. Enter an array from the keyboard
2. Generate an array
3. Show the current array
4. Sort the current array
5. Run tests and save results to a file
0. End program
```

The user can enter an array manually from the keyboard or generate it automatically.

The program can generate four types of arrays:

1. random array,
2. array sorted in ascending order,
3. array sorted in descending order,
4. partially sorted array.

Then the user can choose the sorting method. After sorting is completed, the program displays:

* the array before sorting,
* the array after sorting,
* the name of the method used,
* the number of comparisons,
* the number of swaps.

---

## Automatic Tests

The program has an option to run automatic tests. After choosing the option:

```text
5. Run tests and save results to a file
```

the program performs sorting for arrays of the following lengths:

```text
100
1000
1000000
```

For each length, four types of arrays are generated:

```text
random
sorted in ascending order
sorted in descending order
partially sorted
```

Then each array is sorted using four methods:

```text
Shaker sort
Quick sort Lomuto
Quick sort Hoare
Heap sort
```

The results are saved to the file:

```text
wyniki_sortowania.txt
```

The output file contains a table with:

* sorting method name,
* array length,
* array type,
* number of comparisons,
* number of swaps.

At the end of the file, short conclusions from the performed tests are added.

---

## Counting Comparisons and Swaps

The following structure was used to store the results:

```cpp
struct SortStats {
    long long comparisons = 0;
    long long swaps = 0;
};
```

The `comparisons` field stores the number of comparisons performed during sorting.

The `swaps` field stores the number of element swaps.

The `long long` type was used because, for large arrays, the number of operations can be very large.

---

## Description of the Implemented Algorithms

### Shaker Sort

`Shaker sort` is a variation of bubble sort. In regular bubble sort, the array is scanned only in one direction. In bidirectional bubble sort, passes are performed in two directions:

1. from left to right,
2. from right to left.

During the left-to-right pass, the largest element moves to the end of the unsorted part of the array. During the right-to-left pass, the smallest element moves to the beginning.

The algorithm works well for small or nearly sorted arrays, but it is inefficient for large arrays.

Time complexity:

```text
best case:    O(n)
average case: O(n²)
worst case:   O(n²)
```

Memory complexity:

```text
O(1)
```

---

### Quick Sort with Lomuto Partitioning

Quick sort is a divide-and-conquer algorithm. The Lomuto variant chooses a pivot and then moves elements smaller than or equal to the pivot to the left side of the array. After partitioning is complete, the pivot is in its correct position.

In the project, the pivot is selected as the middle element of the range and then moved to the end so that the Lomuto scheme can be applied.

Advantages of the Lomuto variant:

* simple to understand,
* easy to implement.

Disadvantages:

* it may perform more swaps than the Hoare variant.

Time complexity:

```text
best case:    O(n log n)
average case: O(n log n)
worst case:   O(n²)
```

---

### Quick Sort with Hoare Partitioning

The Hoare variant also uses a pivot, but works differently from Lomuto. It uses two indices:

* one moves from the left side,
* the other moves from the right side.

The indices search for elements that are on the wrong side of the pivot. If such elements are found, they are swapped.

The Hoare variant usually performs fewer swaps than the Lomuto variant.

An important difference is that the Hoare partition function does not return the exact position of the pivot, but the division index of the array.

Time complexity:

```text
best case:    O(n log n)
average case: O(n log n)
worst case:   O(n²)
```

---

### Heap Sort

Heap sort uses the heap data structure. In this project, a max heap was used, where the largest element is located at the beginning of the array.

The algorithm consists of two main stages:

1. building a max heap,
2. repeatedly moving the largest element to the end of the array.

After each movement of the largest element, the heap size is reduced, and the `heapify()` function restores the heap property.

Heap sort is very stable in terms of time complexity because it works in `O(n log n)` time in every case.

Time complexity:

```text
best case:    O(n log n)
average case: O(n log n)
worst case:   O(n log n)
```

Memory complexity:

```text
O(1)
```

---

## Class `cTablica`

The `cTablica` class is responsible for storing the array and performing sorting algorithms.

The most important class field is:

```cpp
std::vector<int> data;
```

The `data` field stores the numbers contained in the array.

The most important class methods are:

```cpp
SortStats shakerSort();
SortStats quickSortLomuto();
SortStats quickSortHoare();
SortStats heapSort();
```

Each method sorts the array and returns the `SortStats` structure with the number of comparisons and swaps.

The class also contains helper functions:

```cpp
void swapElements(int i, int j, SortStats& stats);
int partitionLomuto(int low, int high, SortStats& stats);
int partitionHoare(int low, int high, SortStats& stats);
void heapify(int n, int i, SortStats& stats);
```

The `swapElements()` function swaps two elements and increases the swap counter.

The `partitionLomuto()` and `partitionHoare()` functions are responsible for partitioning the array in the quick sort algorithm.

The `heapify()` function is responsible for restoring the heap property in the heap sort algorithm.

---

## Class `cSortTablicy`

The `cSortTablicy` class is responsible for handling the whole program from the user side.

The most important tasks of this class are:

* displaying the menu,
* reading an array from the keyboard,
* generating arrays,
* choosing the sorting method,
* running tests,
* saving results to a file.

The most important methods of the class are:

```cpp
void menu();
void inputFromKeyboard();
void generateFromKeyboard();
void sortCurrentArray();
void runBenchmark(const std::string& fileName);
```

The `menu()` method handles the main menu of the program.

The `inputFromKeyboard()` method allows the user to enter an array manually.

The `generateFromKeyboard()` method generates an array based on the user's choice.

The `sortCurrentArray()` method sorts the current array using the selected method.

The `runBenchmark()` method performs automatic tests and saves the results to a file.

---

## Error Handling

The program uses exception-based error handling.

If the user enters an incorrect value, for example text instead of a number, the program throws an exception and displays an error message.

Example:

```cpp
throw std::runtime_error("Invalid number entered");
```

Thanks to this, the program does not terminate immediately after an error, but returns to the menu and allows the user to continue working.

---

## Generating a Partially Sorted Array

One of the test data types is a partially sorted array.

First, the program creates an array sorted in ascending order, and then it randomly selects about 10% of the indices. The values at these indices are swapped with each other.

Thanks to this, most of the array remains sorted, but some elements are in incorrect positions.

This makes it possible to check how sorting algorithms work for nearly sorted data.

---

## Important Information About `Shaker sort` for 1,000,000 Elements

`Shaker sort` has time complexity `O(n²)`, so for an array containing `1,000,000` elements, it may run for a very long time.

For this reason, the program includes the question:

```text
Run Shaker sort for 1,000,000 elements? [y/n]
```

If the user chooses `n`, the test will be skipped, and the output file will contain the information:

```text
Skipped
```

This is a practical solution because running an algorithm with `O(n²)` complexity for such a large number of elements can be very time-consuming.

---

## Program Compilation

The program can be compiled using the `g++` compiler.

Example command:

```bash
g++ -std=c++17 main.cpp cTablica.cpp cSortTablicy.cpp -o sortowanie
```

Running the program on Linux or macOS:

```bash
./sortowanie
```

Running the program on Windows:

```bash
sortowanie.exe
```

---

## Example Program Run

After starting the program, the user can choose the option to generate an array. Then the user enters the array length and selects its type.

Example:

```text
Enter array length: 10

Array types:
1. Random
2. Sorted in ascending order
3. Sorted in descending order
4. Partially sorted

Choose array type: 1
```

Then the user can choose the sorting method:

```text
Sorting methods:
1. Shaker sort
2. Quick sort Lomuto
3. Quick sort Hoare
4. Heap sort

Choose sorting method: 4
```

The program will display the array before and after sorting and the statistics:

```text
Method: Heap sort
Number of comparisons: ...
Number of swaps: ...
```

---

## Conclusions

Based on the program's operation, it can be seen that different sorting algorithms have different efficiency depending on the type of input data.

`Shaker sort` is simple to understand and implement, but it is inefficient for large arrays because its complexity is `O(n²)`.

`Quick sort` in both variants usually works very fast, especially for random data. The Hoare variant usually performs fewer swaps than the Lomuto variant.

`Heap sort` has guaranteed `O(n log n)` complexity in every case, so it is well suited for sorting large arrays.

The type of input data has a strong influence on the number of comparisons and swaps. Random, ascending, descending, and partially sorted arrays can produce different results for individual algorithms.

The program makes it possible to compare these differences and save the results in a text file, which makes it easier to analyze the behavior of the implemented sorting methods.
