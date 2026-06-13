#include <iostream>
#include <vector>
#include <string>

#include "dynamic_array_stack.h"
#include "singly_linked_list_stack.h"
#include "std_stack_adapter.h"

void f_printLine() {
    std::cout << "----------------------------------------\n";
}

// Reads number of elements and then reads all values from input
std::vector<int> f_readData() {
    int n;
    std::cin >> n;

    std::vector<int> values;
    values.reserve(n);

    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        values.push_back(x);
    }

    return values;
}

template <typename T>
// Template lets this function work with different stack classes
// as long as they have the same f_top() method
void f_showTop(T& stack) {
    int topValue;
    if (stack.f_top(topValue)) {
        std::cout << "Top element: " << topValue << "\n";
    } else {
        std::cout << "Top element: stack is empty\n";
    }
}

template <typename T>
// Tests all required stack operations and prints results
void f_testStack(const std::string& name, T& stack, const std::vector<int>& values) {
    std::cout << name << "\n";
    f_printLine();

    std::cout << "Is empty at start: " << (stack.f_isEmpty() ? "YES" : "NO") << "\n";
    std::cout << "Size at start: " << stack.f_size() << "\n";
    f_showTop(stack);

    std::cout << "\nPUSH operations:\n";
    for (int value : values) {
        stack.f_push(value);
        std::cout << "push(" << value << ") -> size: " << stack.f_size() << ", ";
        f_showTop(stack);
    }

    std::cout << "\nCurrent size: " << stack.f_size() << "\n";
    f_showTop(stack);

    std::cout << "\nPOP operations:\n";
    while (!stack.f_isEmpty()) {
        int removedValue;
        stack.f_pop(removedValue);
        std::cout << "pop() removed: " << removedValue << " -> size: " << stack.f_size();
        if (!stack.f_isEmpty()) {
            int topValue;
            stack.f_top(topValue);
            std::cout << ", new top: " << topValue << "\n";
        } else {
            std::cout << ", stack is now empty\n";
        }
    }

    std::cout << "\nIs empty at end: " << (stack.f_isEmpty() ? "YES" : "NO") << "\n";
    std::cout << "Size at end: " << stack.f_size() << "\n";
    f_showTop(stack);
    std::cout << "\n";
}

int main() {
    std::vector<int> values = f_readData();

    DynamicArrayStack f_dynamicArrayStack;
    SinglyLinkedListStack f_singlyLinkedListStack;
    StdStackAdapter f_stdStackAdapter;

    f_testStack("A) Stack implemented with one-dimensional dynamic array", f_dynamicArrayStack, values);
    f_testStack("B) Stack implemented with singly linked list", f_singlyLinkedListStack, values);
    f_testStack("C) Stack implemented with std::stack adapter", f_stdStackAdapter, values);

    return 0;
}
