# Laboratory 2 – Identification Grid Matching

This folder contains my solution for the Laboratory 2 assignment. I tried to write the program in a simple and readable way, so the code was divided into several files, and the functions have clear names and comments.

## What is included in the folder

* `main.cpp` – starts the program
* `f_app.*` – main program logic
* `f_io.*` – reading data from files and saving the result
* `f_match.*` – calculating the matching error and selecting the best grid
* `f_types.h` – helper data structures
* `plot_best_fit.py` – Python script for generating plots
* `plot_SEAK.png`, `plot_SEB.png` – ready-made plots
* `wynik_SEAK.txt`, `wynik_SEB.txt` – sample results for the provided data

## Program Assumption

The program compares the grid of an unknown model with 81 identification grids and selects the one for which the matching error is the smallest.

For the calculations, I used the formula from the assignment:

```text
mse = sqrt( sum((y_i - Y_i)^2) + sum((x_i - X_i)^2) )
```

The comparison is performed only for the point coordinates, starting from the 7th element of the row.
The first 6 values are treated as model parameters and are not used when calculating the error.

## Program Compilation

### Version with `g++`

```bash
g++ -std=c++17 main.cpp f_app.cpp f_io.cpp f_match.cpp -o lab2_best_match
```

It is worth noting that `lab2_best_match` after `-o` is only the name of the executable file. It does not have to be the name of the folder.

### Version with `CMake`

```bash
cmake -S . -B build
cmake --build build
```

## Running the Program

After starting the program, it asks the user to enter:

1. the model name,
2. the name of the file with identification grids,
3. the name of the file with the unknown grid,
4. the name of the output file.

Example run for the squirrel-cage asynchronous electric motor:

```text
Model name: Squirrel-cage asynchronous electric motor
Grid file name: siatka_SEAK.txt
Unknown model file name: nmSEAK.txt
Output file name: wynik_SEAK.txt
```

## Important Note About File Paths

During testing, I encountered the following problem:

```text
Error: Cannot open file: siatka_SEAK.txt
```

The reason was simple: the program was being run from the main folder, while the `.txt` files were located in the `Wykresy` subfolder.

In this situation, entering only the file name is not enough. A relative path must be provided, for example:

```text
Model name: Squirrel-cage asynchronous electric motor
Grid file name: Wykresy\siatka_SEAK.txt
Unknown model file name: Wykresy\nmSEAK.txt
Output file name: wynik_SEAK.txt
```

If the output file should also be saved in the same subfolder, then the following can be entered:

```text
Output file name: Wykresy\wynik_SEAK.txt
```

Similarly, for the brushless motor:

```text
Model name: Brushless electric motor
Grid file name: Wykresy\siatkaSEB.txt
Unknown model file name: Wykresy\nmSEB.txt
Output file name: wynik_SEB.txt
```

If all `.txt` files are located in the same folder as the program, then only the file names can be entered, without specifying the path.

## Results for the Provided Data

For the files included with the assignment, the program found:

* for `SEAK` – best match: **grid no. 52**, minimum MSE = **0.131767298**,
* for `SEB` – best match: **grid no. 9**, minimum MSE = **1.181461003**.

## Python Plots

I also prepared a separate Python script for the assignment, which draws a scatter plot of the unknown grid and the best-matching model grid.

Run it with:

```bash
python plot_best_fit.py
```

It is most convenient to keep the `plot_best_fit.py` file and the `.txt` files in the same folder. Then there is no need to change paths in the code.
If the files are located somewhere else, the paths must be adjusted accordingly.

## Additional Note

The code was intentionally divided into several files to make it easier to show what each part of the program is responsible for:

* file reading and writing separately,
* calculations separately,
* program execution separately.

I also added comments above the functions so that, when checking the code, it is immediately clear what each function does.
