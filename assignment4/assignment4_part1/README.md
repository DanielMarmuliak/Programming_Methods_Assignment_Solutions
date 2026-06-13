# Program 01 – Stack Implementation in C++

## Task Description

The program presents **three ways of implementing a stack**:

* **A)** using a one-dimensional dynamic array,
* **B)** using a singly linked list,
* **C)** using the `std::stack` stack adapter from the standard C++ library.

Each implementation performs the required operations:

* checking whether the stack is empty,
* returning the number of elements on the stack,
* reading the element from the top of the stack,
* adding an element to the top of the stack,
* removing an element from the top of the stack.

The program reads data from standard input and demonstrates all operations for each of the three implementations.

---

## File Structure

* `main.cpp` – main program and test of all three stack implementations,
* `dynamic_array_stack.h` – stack implementation using a dynamic array,
* `singly_linked_list_stack.h` – stack implementation using a singly linked list,
* `std_stack_adapter.h` – stack implementation using `std::stack`,
* `README.md` – program description.

---

## Input Format

The first line contains an integer `n` – the number of elements.

The second line contains `n` integers.

### Example Input

```text
5
10 20 30 40 50
```

---

## Output Format

The program prints a demonstration of the operations for each implementation:

* whether the stack is empty,
* what its size is,
* what the top element is,
* what happens after `push`,
* what happens after `pop`.

---

## Compilation

Example compilation command using `g++`:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program01
```

---

## Running the Program

```bash
./program01
```

Then enter the input data according to the task format.

You can also use a test file:

```bash
./program01 < test.txt
```
