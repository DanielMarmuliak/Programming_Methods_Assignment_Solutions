# Problem plecakowy — rozwiązanie rekurencyjne

## Opis programu

Program szuka takiego zestawu elementów, którego suma wag jest dokładnie równa pojemności plecaka.

Jeżeli program znajdzie rozwiązanie, wypisuje wybrane elementy.

Jeżeli rozwiązania nie ma, wypisuje:

```text
BRAK
```

---

## Struktura projektu

Projekt składa się z plików:

```text
main.cpp
BackpackSolver.h
BackpackSolver.cpp
InputOutput.h
InputOutput.cpp
```

---

## Jak działa program?

Program dla każdego elementu sprawdza dwie możliwości:

```text
1. wziąć element
2. pominąć element
```

Robi to rekurencyjnie, czyli funkcja wywołuje samą siebie dla kolejnych elementów.

Jeżeli suma wybranych elementów da pojemność plecaka, program kończy szukanie i wypisuje wynik.

---

## Opis plików

### `main.cpp`

To główny plik programu.

Odpowiada za:

- odczytanie liczby testów,
- odczytanie danych dla każdego testu,
- uruchomienie algorytmu,
- wypisanie wyniku,
- obsługę błędów.

---

### `BackpackSolver.h`

Ten plik zawiera deklarację klasy `BackpackSolver`.

W tej klasie są funkcje odpowiedzialne za rozwiązanie problemu plecakowego.

```cpp
findSolution(...)
solveRecursive(...)
```

---

### `BackpackSolver.cpp`

Ten plik zawiera właściwy algorytm.

Funkcja:

```cpp
findSolution(...)
```

przygotowuje dane i uruchamia rekurencję.

Funkcja:

```cpp
solveRecursive(...)
```

sprawdza możliwe kombinacje elementów.

Najważniejsze warunki:

```cpp
if (remainingCapacity == 0)
    return true;
```

Oznacza, że znaleziono poprawne rozwiązanie.

```cpp
if (remainingCapacity < 0)
    return false;
```

Oznacza, że suma elementów jest za duża.

```cpp
if (index >= weights.size())
    return false;
```

Oznacza, że skończyły się elementy i nie znaleziono rozwiązania.

---

### `InputOutput.h`

Ten plik zawiera deklaracje funkcji do wczytywania i wypisywania danych.

---

### `InputOutput.cpp`

Ten plik zawiera funkcje:

```cpp
readInteger(...)
```

Odczytuje jedną liczbę.

```cpp
readWeights(...)
```

Odczytuje listę wag elementów.

```cpp
printResult(...)
```

Wypisuje wynik programu.

Przykład wyniku:

```text
20 = 8 7 5
```

albo:

```text
BRAK
```

---

## Przykład testowy

### Dane wejściowe

```text
3
20
5
11 8 7 6 5
21
3
5 6 7
20
5
11 7 6 8 5
```

### Oczekiwany wynik

```text
20 = 8 7 5
BRAK
20 = 7 8 5
```

---

## Jak skompilować program?

```bash
g++ main.cpp BackpackSolver.cpp InputOutput.cpp -o backpack.exe
backpack.exe
```

---

## Podsumowanie

Program używa rekurencji do sprawdzenia różnych kombinacji elementów.

Dla każdego elementu program decyduje, czy go wziąć, czy pominąć.


