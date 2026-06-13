#include "cTablica.h"

#include <iostream>
#include <algorithm>

cTablica::cTablica(){}

cTablica::cTablica(const std::vector<int>& values){
    data = values;
}

void cTablica::setData(const std::vector<int>& values){
    data = values;
}

const std::vector<int>& cTablica::getData() const{
    return data;
}

int cTablica::size() const{
    return static_cast<int>(data.size());
}

void cTablica::print(int limit) const{
    if(data.empty()){
        std::cout << "Tablica jest pusta\n";
        return;
    }

    int howMany = std::min(static_cast<int>(data.size()), limit);

    for(int i = 0; i < howMany; i++){
        std::cout << data[i] << " ";
    }

    if(static_cast<int>(data.size()) > limit){
        std::cout << "...";
    }

    std::cout << "\n";
}

void cTablica::swapElements(int i, int j, SortStats& stats){
    if(i != j){
        std::swap(data[i], data[j]);
        stats.swaps++;
    }
}

SortStats cTablica::shakerSort(){
    SortStats stats;
    if(data.size() < 2) return stats;
    
    int left = 0;
    int right = static_cast<int>(data.size()) - 1;
    bool swapped = true;

    while(swapped){
        swapped = false;

        // Move from left to right and push the largest element to the end
        for(int i = left; i < right; i++){
            stats.comparisons++;

            if(data[i] > data[i + 1]){
                swapElements(i, i + 1, stats);
                swapped = true;
            }
        }

        if(!swapped) break;
        right--;
        swapped = false;

        // Move from right to left and push the smallest element to the beginning
        for(int i = right; i > left; i--){
            stats.comparisons++;

            if(data[i - 1] > data[i]){
                swapElements(i - 1, i, stats);
                swapped = true;
            }
        }
        left++;
    }
    return stats;
}

int cTablica::partitionLomuto(int low, int high, SortStats& stats){
    int middle = low + (high - low) / 2;

    // Move the pivot to the end because Lomuto uses the last element as pivot
    swapElements(middle, high, stats);

    int pivot = data[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        stats.comparisons++;

        if(data[j] <= pivot){
            i++;
            swapElements(i, j, stats);
        }
    }
    swapElements(i + 1, high, stats);

    return i + 1;
}

void cTablica::quickSortLomutoRec(int low, int high, SortStats& stats){
    while(low < high){
        int pivotIndex = partitionLomuto(low, high, stats);

        // Sort the smaller part first to reduce recursion depth
        if(pivotIndex - low < high - pivotIndex){
            quickSortLomutoRec(low, pivotIndex - 1, stats);
            low = pivotIndex + 1;
        }else{
            quickSortLomutoRec(pivotIndex + 1, high, stats);
            high = pivotIndex - 1;
        }
    }
}

SortStats cTablica::quickSortLomuto() {
    SortStats stats;
    if(data.size() < 2) return stats;
    quickSortLomutoRec(0, static_cast<int>(data.size()) - 1, stats);

    return stats;
}

int cTablica::partitionHoare(int low, int high, SortStats& stats){
    int pivot = data[low + (high - low) / 2];

    int i = low - 1;
    int j = high + 1;

    while(true){
        do{
            i++;
            stats.comparisons++;
        }while(data[i] < pivot);

        do{
            j--;
            stats.comparisons++;
        }while(data[j] > pivot);

        if (i >= j) return j;

        swapElements(i, j, stats);
    }
}

void cTablica::quickSortHoareRec(int low, int high, SortStats& stats){
    while(low < high){
        int splitIndex = partitionHoare(low, high, stats);

        // Sort the smaller part first to reduce recursion depth
        if(splitIndex - low < high - (splitIndex + 1)){
            quickSortHoareRec(low, splitIndex, stats);
            low = splitIndex + 1;
        }else{
            quickSortHoareRec(splitIndex + 1, high, stats);
            high = splitIndex;
        }
    }
}

SortStats cTablica::quickSortHoare(){
    SortStats stats;
    if(data.size() < 2) return stats;
    quickSortHoareRec(0, static_cast<int>(data.size()) - 1, stats);

    return stats;
}

void cTablica::heapify(int n, int i, SortStats& stats){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n){
        stats.comparisons++;

        if(data[left] > data[largest]) largest = left;
    }

    if(right < n){
        stats.comparisons++;

        if(data[right] > data[largest]) largest = right;
    }

    if(largest != i){
        swapElements(i, largest, stats);
        heapify(n, largest, stats);
    }
}

SortStats cTablica::heapSort() {
    SortStats stats;
    int n = static_cast<int>(data.size());
    if (n < 2) return stats;
    
    // Build the max heap
    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(n, i, stats);
    }

    // Move the largest element to the end of the array
    for(int i = n - 1; i > 0; i--){
        swapElements(0, i, stats);
        heapify(i, 0, stats);
    }
    return stats;
}