# Program 02 – INF <-> ONP Conversion

## Program Description

The program is used to convert expressions written in two notations:

* **INF** – infix notation
* **ONP** – Reverse Polish Notation

The program supports two conversion directions:

* `INF -> ONP`
* `ONP -> INF`

If the expression is incorrect, the program returns `error`.

---

## Supported Elements

### Operands

* lowercase letters from `a` to `z`

### Operators

* `=`
* `<`
* `>`
* `+`
* `-`
* `*`
* `/`
* `%`
* `^`
* `~`

The `~` operator is a unary operator.

### Parentheses

* `(` `)` – only for INF notation

---

## How the Program Works

The program works in several stages:

1. reads the number of tests,
2. reads the following input lines,
3. recognizes whether a line starts with `INF:` or `ONP:`,
4. removes invalid characters from the expression,
5. performs the appropriate conversion,
6. prints the result.

---

## INF -> ONP Conversion

To convert from INF to ONP, the program uses:

* an operator stack,
* operator priorities,
* operator associativity,
* syntax correctness checking.

Operands are added to the result, while operators are placed on the stack and removed according to priorities and parentheses.

---

## ONP -> INF Conversion

To convert from ONP to INF, the program uses:

* a stack of `Expr` objects.

Each stack element stores:

* the expression text,
* the priority of the main operator,
* the main operator,
* information about whether it is a single operand.

Thanks to this, the program can correctly rebuild the INF expression and add only the necessary parentheses.

---

## Error Handling

The program returns `error` when:

* the expression has incorrect syntax,
* operands or operators are missing,
* parentheses are incorrect,
* the final notation does not produce one valid expression.

---

## File Structure

* `main.cpp` – main program
* `helper_funcs.h`, `helper_funcs.cpp` – helper functions
* `expr.h` – `Expr` structure
* `inf_to_onp.h`, `inf_to_onp.cpp` – INF -> ONP conversion
* `onp_to_inf.h`, `onp_to_inf.cpp` – ONP -> INF conversion

---

## Compilation

```bash
g++ main.cpp helper_funcs.cpp inf_to_onp.cpp onp_to_inf.cpp -o program.exe
```
