# Program 01 — General Knapsack Problem

## 1. Program Objective

The objective of the program is to solve the **general knapsack problem** using **dynamic programming**.

The program selects items in such a way that:

* the total mass of the items does not exceed the backpack capacity,
* the total value of the items is as large as possible,
* each type of item can be used any number of times.

This means that this is the **unbounded knapsack** version of the problem, where each item can have an unlimited number of copies.

---

## 2. Project Structure

The program was divided into several thematic files:

```text
main.cpp
items.h
knapsack.h
knapsack.cpp
input.txt
```

This division improves program readability and separates the responsibilities of individual parts of the code.

---

## 3. File Description

### `items.h`

The `items.h` file contains the definition of the `Item` structure.

The structure stores information about one item:

```cpp
std::string name;
int mass;
int value;
```

Meaning of the fields:

* `name` — item name,
* `mass` — item mass,
* `value` — item value.

This file also contains declarations and definitions of the `Item` structure constructors.

The default constructor creates an empty item:

```cpp
Item::Item()
```

The parameterized constructor creates an item based on the given name, mass, and value:

```cpp
Item::Item(std::string itemName, int itemMass, int itemValue)
```

Thanks to this, objects representing items read from the file can be easily created in the program.

---

### `knapsack.h`

The `knapsack.h` file contains the declaration of the `Knapsack` class.

This class is responsible for:

* storing the backpack capacity,
* storing the list of items,
* creating the dynamic arrays `P` and `Q`,
* solving the knapsack problem,
* printing the results.

The most important class fields are:

```cpp
int capacity;
std::vector<Item> items;
std::vector<std::vector<int>> P;
std::vector<std::vector<int>> Q;
```

Meaning of the arrays:

* `P[i][j]` — the best possible value of a backpack with capacity `j` when the first `i` item types can be used,
* `Q[i][j]` — the number of the item selected in the last step for the value stored in `P[i][j]`.

---

### `knapsack.cpp`

The `knapsack.cpp` file contains the definitions of the `Knapsack` class methods.

This is where the main dynamic programming algorithm is located, as well as the functions used to print data from the `P` and `Q` arrays, the function that prints all items with their values, and the function that prints the highest obtained value.

---

### `main.cpp`

The `main.cpp` file is responsible for starting the program.

It performs the following steps:

1. Opens the `input.txt` file.
2. Reads the backpack capacity.
3. Reads the list of items.
4. Checks basic input data errors.
5. Creates an object of the `Knapsack` class.
6. Calls the algorithm that solves the problem.
7. Prints the items, the `P` and `Q` arrays, and the best result.

---

## 4. Input Data Format

The input data is located in the `input.txt` file.

The first line contains the backpack capacity:

```text
10
```

Each following line contains data for one item:

```text
name value mass
```

Example:

```text
10
Koszula 75 7
Spodnie 150 8
Bluza 250 6
Czapka 35 4
Szalik 10 3
Buty 100 9
```

In this example, the backpack capacity is `10`.

---

## 5. Main Idea of the Algorithm

The algorithm uses dynamic programming.

For each item `i` and each backpack capacity `j`, the program checks two possibilities:

### Option 1 — do not take the current item

Then the best result is the same as in the previous row:

```cpp
P[i - 1][j]
```

This means that the current item is ignored and only the previous items are used.

---

### Option 2 — take the current item

If the mass of the current item fits into the current backpack capacity, it can be added:

```cpp
P[i][j - currMass] + currVal
```

`P[i][...]` is used instead of `P[i - 1][...]` because in the general knapsack problem the same item can be selected many times.

---

## 6. Dynamic Formula

For each `i` and `j`, the program chooses the greater value:

```cpp
P[i][j] = max(
    P[i - 1][j],
    P[i][j - currMass] + currVal
)
```

The second option is possible only when:

```cpp
currMass <= j
```

If the item does not fit into the backpack, the program copies the value from the previous row:

```cpp
P[i][j] = P[i - 1][j]
```

---

## 7. Function Description

### `Knapsack::Knapsack(int backpackCap, std::vector<Item> itemList)`

Constructor of the `Knapsack` class.

It stores the backpack capacity and the list of items, and then creates the `P` and `Q` arrays.

The arrays have the following size:

```text
number_of_items + 1
backpack_capacity + 1
```

The additional row and additional column are needed for the base case, which is the situation when:

* there are no items,
* the backpack capacity is `0`.

---

### `Knapsack::solve()`

The most important function of the program.

It fills the `P` and `Q` arrays.

How the function works:

1. It iterates through all items.
2. For each item, it iterates through all possible backpack capacities.
3. It checks whether the current item fits into the current capacity.
4. It calculates the result without the current item.
5. It calculates the result with the current item.
6. It compares both results.
7. It stores the better result in the `P` array.
8. It stores information about the selected item in the `Q` array.

The part responsible for the decision:

```cpp
if(optionWithItem > optionWithoutItem){
    P[i][j] = optionWithItem;
    Q[i][j] = i;
}else{
    P[i][j] = optionWithoutItem;
    Q[i][j] = Q[i - 1][j];
}
```

If choosing the current item gives a better value, the program stores this value and the item number.

If a better or equal result was already available earlier, the program copies the value from the previous row.

---

### `Knapsack::printItems() const`

This function prints all items read from the file.

For each item, it prints:

* item number,
* name,
* mass,
* value.

---

### `Knapsack::printTableP() const`

This function prints the `P` array.

The `P` array shows the best values for consecutive backpack capacities and consecutive sets of available items.

Row `i` means that the first `i` items can be used.

Column `j` means that the backpack capacity is equal to `j`.

---

### `Knapsack::printTableQ() const`

This function prints the `Q` array.

The `Q` array shows which item was selected last when obtaining the value stored in the `P` array.

Thanks to this array, it is possible to later reconstruct which items make up the best solution.

---

### `Knapsack::printBestValue() const`

This function prints the best possible backpack value.

This value is located in the last cell of the `P` array:

```cpp
P[n][capacity]
```

where:

* `n` — number of items,
* `capacity` — backpack capacity.

---

## 8. Example Program Output

For the following input data:

```text
10
Koszula 75 7
Spodnie 150 8
Bluza 250 6
Czapka 35 4
Szalik 10 3
Buty 100 9
```

the program prints:

```text
Items:
1. Koszula | mass: 7 | value: 75
2. Spodnie | mass: 8 | value: 150
3. Bluza | mass: 6 | value: 250
4. Czapka | mass: 4 | value: 35
5. Szalik | mass: 3 | value: 10
6. Buty | mass: 9 | value: 100

Table P - best values:

  i/j    0    1    2    3    4    5    6    7    8    9   10
    0    0    0    0    0    0    0    0    0    0    0    0
    1    0    0    0    0    0    0    0   75   75   75   75
    2    0    0    0    0    0    0    0   75  150  150  150
    3    0    0    0    0    0    0  250  250  250  250  250
    4    0    0    0    0   35   35  250  250  250  250  285
    5    0    0    0   10   35   35  250  250  250  260  285
    6    0    0    0   10   35   35  250  250  250  260  285

Table Q - last chosen item:

  i/j    0    1    2    3    4    5    6    7    8    9   10
    0    0    0    0    0    0    0    0    0    0    0    0
    1    0    0    0    0    0    0    0    1    1    1    1
    2    0    0    0    0    0    0    0    1    2    2    2
    3    0    0    0    0    0    0    3    3    3    3    3
    4    0    0    0    0    4    4    3    3    3    3    4
    5    0    0    0    5    4    4    3    3    3    5    4
    6    0    0    0    5    4    4    3    3    3    5    4

Best value: 285
```

The best value is `285`.

This result can be achieved for a backpack with capacity `10`.

---

## 9. Program Compilation

The program can be compiled with the command:

```bash
g++ main.cpp knapsack.cpp -o program
```

Running the program:

```bash
./program
```

---

## 10. Summary

The program solves the general knapsack problem using dynamic programming.

The most important part of the program is the `P` array, which stores the best values for consecutive backpack capacities.

The `Q` array stores information about the last selected item, which allows the process of building the solution to be analyzed.

Thanks to the use of dynamic programming, the program does not manually check all possible combinations, but gradually builds the solution based on previously calculated results.
