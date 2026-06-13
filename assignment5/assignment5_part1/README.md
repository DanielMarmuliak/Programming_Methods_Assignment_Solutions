# Task: Incidence Matrix of a Directed Graph

## Task Topic

Writing a program that, for a directed graph:

* reads input data in the form of an edge list,
* determines the number of vertices,
* creates an incidence matrix,
* prints the incidence matrix,
* prints the neighbors of each vertex.

---

## Task Description

The program should read a directed graph stored in a text file or provided through standard input in the form of an edge list.

Input data format:

* the first line contains the number `k`, which represents the number of edges,
* the next `k` lines contain pairs of integers `u v`, which represent a directed edge from vertex `u` to vertex `v`.

Based on this data, the program should:

1. read all edges,
2. determine the number of vertices,
3. build an incidence matrix for the directed graph,
4. print the created matrix,
5. print the neighbors of each vertex.

---

## Program Assumptions

The following assumptions were made in the program:

* the graph is **directed**,
* vertices are numbered with positive integers, starting from `1`,
* the number of vertices is determined based on the largest vertex number appearing in the input data,
* each column of the incidence matrix corresponds to exactly one edge,
* the following notation is used in the incidence matrix:

  * `-1` — the beginning of an edge,
  * `1` — the end of an edge,
  * `0` — no relation between the given vertex and the given edge.

---

## How the Program Works

### 1. Reading the Data

The program reads the number of edges `k`, and then stores all edges in a vector of `Edge` structures.

Example input data:

```text
5
1 2
2 3
1 3
3 4
4 2
```

## Example Program Output

### Incidence Matrix

```text
-1 0 -1 0 0
1 -1 0 0 1
0 1 1 -1 0
0 0 0 1 -1
```

### Vertex Neighbors

```text
Neighbors of 1: 2 3
Neighbors of 2: 3
Neighbors of 3: 4
Neighbors of 4: 2
```

## Compilation

```bash
g++ main.cpp graph.cpp incidence_matrix.cpp -o graph_program
```
