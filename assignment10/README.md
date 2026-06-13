# Laboratory 10 — Huffman Algorithm

## Task Topic

The aim of the task is to implement the Huffman algorithm, which is used to build an optimal prefix code for given symbols and their frequencies.

The program uses:

* division of the program into header and implementation files,
* thematic grouping of functions,
* a priority queue,
* a Huffman binary tree,
* recursive code generation,
* custom exception classes derived from `std::runtime_error`,
* error handling using `try-catch`.

---

## Project Structure

The project consists of the following files:

```text
main.cpp
Huffman.h
Huffman.cpp
InputData.h
InputData.cpp
Exceptions.h
README.md
```

### File Description

#### `main.cpp`

The main program file.
It contains the `main()` function, the program menu, and the helper function `runHuffmanExample()`, which starts the whole Huffman coding process for the selected data set.

#### `Huffman.h`

A header file containing declarations of structures and functions related to the Huffman algorithm.

It includes, among others:

* the `Node` structure,
* the `SymbolData` structure,
* the `CompareNodes` structure,
* declarations of functions for building the tree, generating codes, printing results, and deleting the tree.

#### `Huffman.cpp`

An implementation file containing the actual logic of the Huffman algorithm.

The following functions are implemented here:

* `buildHuffmanTree()`,
* `generateCodes()`,
* `printCodes()`,
* `deleteTree()`.

#### `InputData.h`

A header file with declarations of functions responsible for input data and its validation.

#### `InputData.cpp`

An implementation file containing sample data sets and the `validateInput()` function.

This function checks whether the data is correct before the Huffman tree is built.

#### `Exceptions.h`

A file containing custom exception classes derived from `std::runtime_error`.

---

## Description of the Huffman Algorithm

The Huffman algorithm is used to create an optimal prefix code.

This means that:

* symbols that occur more often receive shorter codes,
* symbols that occur less often receive longer codes,
* no code is the beginning of another code.

Thanks to this, encoded text can take up less space.

---

## How the Program Works

The program works according to the following scheme:

1. The user selects a data set from the menu.
2. The program checks the correctness of the input data.
3. A separate leaf of the tree is created for each symbol.
4. All leaves are added to the priority queue.
5. The program takes two nodes with the lowest frequency from the queue.
6. A new parent node is created from these two nodes.
7. The new node is added back to the queue.
8. Steps 5–7 are repeated until only one element remains in the queue.
9. The last element in the queue becomes the root of the Huffman tree.
10. The program recursively traverses the tree and generates codes.
11. The results are printed on the screen.
12. The tree is deleted from memory.

---

## Priority Queue

The program uses a priority queue:

```cpp
std::priority_queue<Node*, std::vector<Node*>, CompareNodes> pq;
```

By default, `priority_queue` in C++ places the largest element at the front.

In the Huffman algorithm, we need the opposite — the elements with the smallest frequencies must be at the front.

Therefore, a custom comparator was used:

```cpp
struct CompareNodes {
    bool operator()(Node* first, Node* second) const {
        return first->frequency > second->frequency;
    }
};
```

Thanks to this, the priority queue works in such a way that the node with the smallest `frequency` value is at the front.

---

## Generating Huffman Codes

The recursive function used to generate the codes is:

```cpp
void generateCodes(Node* root, const std::string& currentCode,
                   std::map<char, std::string>& codes);
```

The function traverses the completed Huffman tree.

The following rule is used:

```text
move left  -> 0
move right -> 1
```

If the function reaches a leaf, it saves the final code for the symbol stored in that leaf.

Example:

```text
root -> left         = 0
root -> right left   = 10
root -> right right  = 11
```

---

## Exception Handling

The project implements custom exception classes derived from `std::runtime_error`.

The `Exceptions.h` file includes, among others:

```cpp
class EmptyInputException : public std::runtime_error
```

```cpp
class TooFewSymbolsException : public std::runtime_error
```

```cpp
class InvalidFrequencyException : public std::runtime_error
```

```cpp
class DuplicateSymbolException : public std::runtime_error
```

Exceptions are thrown in the `validateInput()` function.

For example:

```cpp
if (symbols.empty()) {
    throw EmptyInputException();
}
```

In the `main()` function, exceptions are caught using the block:

```cpp
try {
    // program code
}
catch (const std::exception& e) {
    std::cout << "ERROR: " << e.what() << "\n";
}
```

Because the custom exceptions inherit from `std::runtime_error`, and `std::runtime_error` inherits from `std::exception`, all of them can be handled with one `catch` block.

---

## Example Correct Data

### Data from Task A

```text
A 12
B 7
I 18
M 10
S 9
X 5
Z 2
```

### Data from Task B

```text
c 0.11
e 0.22
i 0.16
r 0.12
s 0.15
t 0.10
x 0.14
```

---

## Example Incorrect Data

The program shows how exceptions work for different types of incorrect input data.

### Negative Frequency

```text
A 12
B -7
C 5
```

Result:

```text
Error: The frequency or probability must be greater than zero
```

### Repeated Symbol

```text
A 12
B 7
A 5
```

Result:

```text
Error: The same symbol cannot appear more than once
```

### Only One Symbol

```text
A 12
```

Result:

```text
Error: To build a Huffman tree, at least two symbols are needed
```

### Empty Data List

Result:

```text
Error: The input list is empty
```

---

## Program Compilation

The program can be compiled with the command:

```bash
g++ main.cpp Huffman.cpp InputData.cpp -o program
```

---

## Running the Program

On Linux / macOS:

```bash
./program
```

On Windows:

```bash
program.exe
```

---

## Conclusions

The task uses a binary tree and a priority queue to implement the Huffman algorithm. Thanks to the custom comparator, the priority queue returns the elements with the smallest frequencies first. Recursive traversal of the tree allows binary codes to be generated for all symbols.

The use of custom exception classes made error handling more organized and allowed the program to present its reaction to different types of incorrect input data.
