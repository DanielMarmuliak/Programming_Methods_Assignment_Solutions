#include "linked_list.h"

LinkedList& LinkedList::operator=(const LinkedList& other){
    if(this != &other) {
        f_clear();
        f_copyFrom(other);
    }
    return *this;
}

void LinkedList::f_copyFrom(const LinkedList& other){
    Node* current = other.head;
    while(current != nullptr) {
        f_pushBack(current->value);
        current = current->next;
    }
}

void LinkedList::f_clear(){
    Node* current = head;
    while(current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
    tail = nullptr;
    count = 0;
}

void LinkedList::f_pushBack(int value){
    Node* newNode = new Node(value);

    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }else{
        tail->next = newNode;
        tail = newNode;
    }
    count++;
}

int LinkedList::f_size() const{
    return count;
}

bool LinkedList::f_isEmpty() const{
    return head == nullptr;
}

void LinkedList::f_print() const{
    Node* current = head;
    if(current == nullptr){
        std::cout << "(empty)";
        return;
    }
    while(current != nullptr){
        std::cout << current->value;
        if(current->next != nullptr){
            std::cout << " -> ";
        }
        current = current->next;
    }
}
