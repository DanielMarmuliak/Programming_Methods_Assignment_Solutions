#ifndef CTABLICA_H
#define CTABLICA_H

#include <vector>
#include "SortStats.h"

class cTablica{
private:
    std::vector<int> data;

    // Swaps two elements and counts the swap
    void swapElements(int i, int j, SortStats& stats);

    // Partitions the array using the Lomuto scheme
    int partitionLomuto(int low, int high, SortStats& stats);

    // Recursive function for quick sort with Lomuto partition
    void quickSortLomutoRec(int low, int high, SortStats& stats);

    // Partitions the array using the Hoare scheme
    int partitionHoare(int low, int high, SortStats& stats);

    // Recursive function for quick sort with Hoare partition
    void quickSortHoareRec(int low, int high, SortStats& stats);

    // Restores the max-heap property
    void heapify(int n, int i, SortStats& stats);

public:
    // Creates an empty array
    cTablica();

    // Creates an array from the given vector
    explicit cTablica(const std::vector<int>& values);

    // Sets new data in the array
    void setData(const std::vector<int>& values);

    // Returns the data stored in the array
    const std::vector<int>& getData() const;

    // Returns the number of elements in the array
    int size() const;

    // Prints the array to the console
    void print(int limit = 50) const;

    // Sorts the array using shaker sort
    SortStats shakerSort();

    // Sorts the array using quick sort with Lomuto partition
    SortStats quickSortLomuto();

    // Sorts the array using quick sort with Hoare partition
    SortStats quickSortHoare();

    // Sorts the array using heap sort
    SortStats heapSort();
};

#endif