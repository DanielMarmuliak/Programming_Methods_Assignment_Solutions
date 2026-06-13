# Searching for Element `k` in a Sorted 2D Matrix

## Program Objective

The program is used to search for a given integer `k` in a two-dimensional array of integers with dimensions `n × m`.

The following assumptions are made about the matrix:

* each row is sorted in non-decreasing order,
* each column is sorted in non-decreasing order.

For the given value `k`, the program determines:

* the **first occurrence** of the element using the **iterative** method,
* the **last occurrence** of the element using the **iterative** method,
* the **first occurrence** of the element using the **recursive** method,
* the **last occurrence** of the element using the **recursive** method.

If the searched element does not occur in the matrix, the program prints an appropriate message.

---

## How the Program Works

The program starts by reading:

1. the number of data sets,
2. for each data set:

   * the number of rows `n`,
   * the number of columns `m`,
   * the matrix elements,
   * the value `k` to be found.

After reading the data for each data set, the program runs four independent search procedures and prints their results.

---

## Applied Approach

The program uses the fact that **each row of the matrix is sorted**.
Because of this, instead of checking every element separately, the program applies **binary search** in each row, which significantly speeds up the program.

### Iterative Version

* the matrix is searched row by row,
* in each row, **iterative binary search** is performed.

### Recursive Version

* consecutive rows of the matrix are searched recursively,
* in each row, **recursive binary search** is performed.

---

## Program Structure

The program is divided into three files:

* **`main.cpp`** – responsible for reading input data, calling functions, and printing results,
* **`search.h`** – contains structure and function declarations,
* **`search.cpp`** – contains definitions of the search functions.

This division improves code readability and makes the program easier to develop.

---

## Description of Used Elements

### `Result` Structure

The `Result` structure stores the search result and contains three fields:

* `found` – information whether the element was found,
* `row` – row number,
* `column` – column number.

---

## Function Description

### Iterative Functions

#### `f_findFirstInRow`

This function performs iterative binary search in one row and returns the position of the **first occurrence** of element `k`.

#### `f_findLastInRow`

This function performs iterative binary search in one row and returns the position of the **last occurrence** of element `k`.

#### `f_iterativeFirst`

This function searches the matrix **from the first row to the last row** and returns the **first occurrence** of the searched element.

#### `f_iterativeLast`

This function searches the matrix **from the last row to the first row** and returns the **last occurrence** of the searched element.

---

### Recursive Functions

#### `f_recFindFirstInRow`

This function recursively performs binary search in one row and finds the **first occurrence** of element `k`.

#### `f_recMatrixFirst`

This function recursively searches consecutive rows of the matrix **from top to bottom**.

#### `f_recursiveFirst`

This function starts the recursive search for the **first occurrence** of the element in the entire matrix.

#### `f_recFindLastInRow`

This function recursively performs binary search in one row and finds the **last occurrence** of element `k`.

#### `f_recMatrixLast`

This function recursively searches consecutive rows of the matrix **from bottom to top**.

#### `f_recursiveLast`

This function starts the recursive search for the **last occurrence** of the element in the entire matrix.

---

### Main Function

#### `main`

The `main` function is responsible for:

* reading input data,
* creating the matrix,
* calling all search functions,
* printing the results to the screen.

---

## Time Complexity

Searching in one row is performed using binary search, so its time complexity is:

* **`O(log m)`**

Since in the worst case all `n` rows are searched, the total time complexity of the program is:

* **`O(n log m)`**

This solution is much more efficient than linearly checking all elements of the matrix.

---

## Program Compilation

The program can be compiled using the `g++` compiler with the following command:

```bash
g++ main.cpp search.cpp -o program
```
