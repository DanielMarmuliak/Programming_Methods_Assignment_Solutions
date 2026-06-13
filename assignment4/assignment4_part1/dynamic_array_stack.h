#ifndef DYNAMIC_ARRAY_STACK_H
#define DYNAMIC_ARRAY_STACK_H

#include <cstddef>

class DynamicArrayStack {
private:
    int* data;
    int currentSize;
    int capacity;

    void f_resize() {
        int newCapacity = (capacity == 0) ? 1 : capacity * 2;
        int* newData = new int[newCapacity];

        for (int i = 0; i < currentSize; ++i) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    DynamicArrayStack() 
    : data(nullptr), currentSize(0), capacity(0) {}

    ~DynamicArrayStack() {
        delete[] data;
    }

    bool f_isEmpty() const {
        return currentSize == 0;
    }

    int f_size() const {
        return currentSize;
    }

    void f_push(int value) {
        if (currentSize == capacity) {
            f_resize();
        }
        data[currentSize] = value;
        ++currentSize;
    }

    bool f_top(int& value) const {
        if (f_isEmpty()) {
            return false;
        }
        value = data[currentSize - 1];
        return true;
    }

    bool f_pop(int& value) {
        if (f_isEmpty()) {
            return false;
        }
        value = data[currentSize - 1];
        --currentSize;
        return true;
    }
};

#endif
