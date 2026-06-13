# Program 01 – Implementacja stosu w C++

## Opis zadania
Program przedstawia **trzy sposoby implementacji stosu**:

- **A)** w tablicy dynamicznej jednowymiarowej,
- **B)** za pomocą listy jednokierunkowej,
- **C)** za pomocą adaptera stosu `std::stack` ze standardowej biblioteki C++.

Każda implementacja realizuje wymagane operacje:

- sprawdzenie, czy stos jest pusty,
- zwrócenie liczby elementów na stosie,
- odczyt elementu ze szczytu stosu,
- dodanie elementu na szczyt stosu,
- zdjęcie elementu ze szczytu stosu.

Program wczytuje dane ze standardowego wejścia i dla każdej z trzech implementacji pokazuje działanie wszystkich operacji.

---

## Struktura plików

- `main.cpp` – program główny i test działania wszystkich trzech stosów,
- `dynamic_array_stack.h` – implementacja stosu na tablicy dynamicznej,
- `singly_linked_list_stack.h` – implementacja stosu na liście jednokierunkowej,
- `std_stack_adapter.h` – implementacja stosu z użyciem `std::stack`,
- `README.md` – opis programu.

---

## Format wejścia
Pierwsza linia zawiera liczbę całkowitą `n` – liczbę elementów.

W drugiej linii znajduje się `n` liczb całkowitych.

### Przykład wejścia
```text
5
10 20 30 40 50
```

---

## Format wyjścia
Program wypisuje demonstrację działania operacji dla każdej implementacji:

- czy stos jest pusty,
- jaki ma rozmiar,
- jaki jest element na szczycie,
- co dzieje się po `push`,
- co dzieje się po `pop`.

---

## Kompilacja
Przykładowa komenda kompilacji w `g++`:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program01
```

---

## Uruchomienie
```bash
./program01
```

Następnie należy podać dane wejściowe zgodnie z formatem zadania.

Można też użyć pliku testowego:

```bash
./program01 < test.txt
```

