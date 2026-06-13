#ifndef SINGLY_LINKED_LIST_STACK_H
#define SINGLY_LINKED_LIST_STACK_H

class SinglyLinkedListStack {
private:
    struct Node {
        int value;
        Node* next;

        Node(int newValue, Node* newNext) 
        : value(newValue), next(newNext) {}
    };

    Node* head;
    int currentSize;

public:
    SinglyLinkedListStack() 
    : head(nullptr), currentSize(0) {}

    ~SinglyLinkedListStack() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool f_isEmpty() const {
        return head == nullptr;
    }

    int f_size() const {
        return currentSize;
    }

    void f_push(int value) {
        head = new Node(value, head);
        ++currentSize;
    }

    bool f_top(int& value) const {
        if (f_isEmpty()) {
            return false;
        }
        value = head->value;
        return true;
    }

    bool f_pop(int& value) {
        if (f_isEmpty()) {
            return false;
        }
        Node* temp = head;
        value = head->value;
        head = head->next;
        delete temp;
        --currentSize;
        return true;
    }
};

#endif
