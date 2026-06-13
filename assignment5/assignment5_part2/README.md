# Task: Incidence List of an Undirected Graph

## Task Description

The program reads the definition of the edges of an undirected graph from standard input.
Based on this data, it creates an **array of incidence lists** and then determines the **degrees of all vertices**.

---

## File Structure

* `main.cpp` – starts the program
* `graph.h` – declarations of graph-related functions
* `graph.cpp` – definitions of graph-related functions
* `linked_list.h` – declaration of the singly linked list class
* `linked_list.cpp` – definition of the singly linked list class
* `example_input.txt` – sample test data

---

## How the Program Works

### 1. Reading the Data

The program reads:

* in the first line, an integer `k` – the number of edges,
* in the next `k` lines, pairs of numbers `u v`, which represent an edge between vertices `u` and `v`.

Example:

```text
5
1 2
1 3
2 4
3 4
4 5
```

### 2. Determining the Number of Vertices

The program finds the largest vertex number appearing in the input data.
Based on this value, it creates an array of incidence lists from `1` to `max`.

### 3. Building the Incidence Lists

Because the graph is **undirected**, each edge `u v` is added to two lists:

* `v` is added to the list of vertex `u`,
* `u` is added to the list of vertex `v`.

As a result, each list contains all neighbors of the given vertex.

### 4. Determining Vertex Degrees

The degree of a vertex is equal to the number of elements in its incidence list.
The program uses the `count` field in the `LinkedList` class for this.

---

## Short Description of the Custom Singly Linked List

The `LinkedList` class stores:

* a pointer to the first element (`head`),
* a pointer to the last element (`tail`),
* the number of elements (`count`).

The most important methods are:

* `f_pushBack(int value)` – adds an element to the end of the list,
* `f_clear()` – removes all elements,
* `f_size()` – returns the number of elements,
* `f_print()` – prints the contents of the list.

---

## Compilation

Run the following command in the folder containing the files:

```bash
g++ main.cpp graph.cpp linked_list.cpp -o program
```

## Running the Program

The program uses **standard input**, so the most convenient way to run it is by redirecting a file:

```bash
./program02 < example_input.txt
```

You can also enter the data manually after starting the program:

```bash
./program02
```

---

## Example for Testing the Program

### File `example_input.txt`

```text
9
1 2
2 5
1 5
1 4
1 3
2 4
2 3
4 5
4 3
```

### Expected Output

```text
Incidence List:
1: 2 -> 5 -> 4 -> 3
2: 1 -> 5 -> 4 -> 3
3: 1 -> 2 -> 4
4: 1 -> 2 -> 5 -> 3
5: 2 -> 1 -> 4

Vertex degrees:
deg(1) = 4
deg(2) = 4
deg(3) = 3
deg(4) = 4
deg(5) = 3
```
