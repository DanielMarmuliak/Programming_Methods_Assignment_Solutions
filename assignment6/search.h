#ifndef SEARCH_H
#define SEARCH_H
#include <vector>

// Stores information about the search result:
// whether the element was found and its position in the matrix
struct Result {
    bool found;
    int row;
    int column;
};

// Iteratively finds the first occurrence of k in a sorted row
// Returns the index of the first occurrence or -1 if k is not present
int f_findFirstInRow(const std::vector<int>& row, int m, int k);

// Iteratively finds the last occurrence of k in a sorted row
// Returns the index of the last occurrence or -1 if k is not present
int f_findLastInRow(const std::vector<int>& row, int m, int k);

// Public recursive function that starts searching
// for the first occurrence of k from the first row.
Result f_recursiveFirst(const std::vector<std::vector<int>>& matrix, int n, int m,int k);

// Public recursive function that starts searching
// for the last occurrence of k from the last row
Result f_recursiveLast(const std::vector<std::vector<int>>& matrix, int n, int m,int k);

// Iteratively searches the matrix from top to bottom
// and returns the lexicographically first occurrence of k
Result f_iterativeFirst(const std::vector<std::vector<int>>& matrix, int n, int m,int k);

// Iteratively searches the matrix from bottom to top
// and returns the lexicographically last occurrence of k
Result f_iterativeLast(const std::vector<std::vector<int>>& matrix, int n, int m,int k);


#endif