# Laboratory 9 

## Task Topic

The program solves the 0/1 knapsack problem using a backtracking algorithm and the branch and bound method.

In this task, there are 5 items and a backpack with capacity `W = 19`. Each item has:

* `p` — profit / value,
* `w` — weight,
* `p/w` — profit-to-weight ratio.

The goal is to choose such items that the backpack capacity is not exceeded and the maximum possible profit is obtained.

## Data Used in the Program

| i |  p |  w | p/w |
| - | -: | -: | --: |
| 1 | 20 |  2 |  10 |
| 2 | 30 |  5 |   6 |
| 3 | 35 |  7 |   5 |
| 4 | 12 |  3 |   4 |
| 5 |  3 |  1 |   3 |

## How the Program Works

1. The program creates a list of items according to the table from the assignment.
2. The items are sorted in descending order by the `p/w` value.
3. The algorithm builds a decision tree.
4. For each item, two possibilities are checked:

   * take the item into the backpack,
   * do not take the item into the backpack.
5. For each node, the `bound` is calculated, which means the optimistic maximum profit that can be obtained from this place in the tree.
6. If a node cannot give a better result than the current best solution, the program cuts it off.
7. At the end, the program saves the best result to the file `wynik.txt`.

## Formula for the Bound

The bound is calculated based on the idea of the fractional knapsack problem. The program adds whole next items as long as they fit into the backpack. If the next item no longer fits, the program adds only its possible fractional part to calculate the theoretical bound.

In simplified form:

```text
bound = current_profit + profit_of_next_items + free_space * (p/w of the next item)
```

Thanks to this, we know whether it is worth continuing to develop a given node of the tree.

## File Structure

```text
lab9_Danylo_Marmulyak/
│
├── main.cpp                          # main program file
├── Item.h                            # structure of one item
├── KnapsackSolver.h                  # declaration of the class solving the problem
├── KnapsackSolver.cpp                # algorithm implementation
└── README.md                         # task description
```

## Compilation

The program can be compiled with the command:

```bash
g++ main.cpp KnapsackSolver.cpp -o program01
```

## Running the Program

After compilation, run the program:

```bash
./program01
```

The program will create the file:

```text
wynik.txt
```

The file `wynik.txt` contains all steps of the algorithm: the current node, profit, weight, calculated bound, decisions about adding or skipping an item, and the final result.

## Result for the Task Data

For the given data, the best solution is to take all items:

```text
Items: 1, 2, 3, 4, 5
Total weight: 18
Maximum profit: 100
Remaining backpack capacity: 1
```

The result is correct because the total weight of all items is `18`, and the backpack capacity is `19`, so all items fit into the backpack.

To complete the task, we used:

* recursion,
* a backtracking algorithm,
* the branch and bound method,
* sorting items by `p/w`.

## Short Summary

The program checks different combinations of items, but it does not always have to analyze the entire tree to the end. If the calculated bound shows that a given node cannot produce a better result than the current best solution, further checking of that branch is skipped. Thanks to this, the algorithm works clearly and shows how the number of checked cases can be reduced.
