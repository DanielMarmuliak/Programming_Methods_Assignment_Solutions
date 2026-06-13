#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

struct Node {
    int value;
    Node* next;

    Node(int newValue){
        value = newValue;
        next = nullptr;
    } 
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int count;

    // Copies all nodes from another list
    void f_copyFrom(const LinkedList& other);

public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    // Creates a copy of a list
    LinkedList(const LinkedList& other) {
        head = nullptr;
        tail = nullptr;
        count = 0;
        f_copyFrom(other);
    }

    // Assigns data from another list
    LinkedList& operator=(const LinkedList& other);

    ~LinkedList() {
        f_clear();
    }

    // Removes all elements from the list
    void f_clear();

    // Adds a value at the end of the list
    void f_pushBack(int value);

    // Returns the number of elements
    int f_size() const;

    // Checks if the list is empty
    bool f_isEmpty() const;

    // Prints the list elements.
    void f_print() const;
};

#endif
