# Zadanie: Lista incydencji grafu nieskierowanego

## Opis zadania
Program odczytuje z wejścia standardowego definicję krawędzi grafu nieskierowanego.
Na tej podstawie tworzy **tablicę list incydencji**, a następnie wyznacza **stopnie wszystkich wierzchołków**.

---

## Struktura plików

- `main.cpp` – uruchomienie programu
- `graph.h` – deklaracje funkcji związanych z grafem
- `graph.cpp` – definicje funkcji związanych z grafem
- `linked_list.h` – deklaracja klasy listy jednokierunkowej
- `linked_list.cpp` – definicja klasy listy jednokierunkowej
- `example_input.txt` – przykładowe dane testowe

---

## Jak działa program

### 1. Wczytanie danych
Program wczytuje:
- w pierwszej linii liczbę całkowitą `k` – liczbę krawędzi,
- w kolejnych `k` wierszach pary liczb `u v`, które oznaczają krawędź między wierzchołkami `u` i `v`.

Przykład:
```text
5
1 2
1 3
2 4
3 4
4 5
```

### 2. Wyznaczenie liczby wierzchołków
Program znajduje największy numer wierzchołka występujący w danych.
Na tej podstawie tworzy tablicę list incydencji od `1` do `max`.

### 3. Budowa list incydencji
Ponieważ graf jest **nieskierowany**, każda krawędź `u v` jest dopisywana do dwóch list:
- `v` trafia do listy wierzchołka `u`,
- `u` trafia do listy wierzchołka `v`.

Dzięki temu każda lista zawiera wszystkich sąsiadów danego wierzchołka.

### 4. Wyznaczenie stopni wierzchołków
Stopień wierzchołka jest równy liczbie elementów w jego liście incydencji.
Program korzysta tutaj z pola `count` w klasie `LinkedList`.

---

## Krótki opis własnej listy jednokierunkowej
Klasa `LinkedList` przechowuje:
- wskaźnik na pierwszy element (`head`),
- wskaźnik na ostatni element (`tail`),
- liczbę elementów (`count`).

Najważniejsze metody:
- `f_pushBack(int value)` – dodaje element na koniec listy,
- `f_clear()` – usuwa wszystkie elementy,
- `f_size()` – zwraca liczbę elementów,
- `f_print()` – wypisuje zawartość listy.

---

## Kompilacja

W katalogu z plikami uruchomić:

```bash
g++ main.cpp graph.cpp linked_list.cpp -o program
```


## Uruchomienie programu
Program korzysta ze **standardowego wejścia**, więc najwygodniej uruchomić go z przekierowaniem pliku:

```bash
./program02 < example_input.txt
```

Można też wpisać dane ręcznie po uruchomieniu:

```bash
./program02
```

---

## Przykład do sprawdzenia programu

### Plik `example_input.txt`
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

### Oczekiwany wynik
```text
Incedence List:
1: 2 -> 5 -> 4 -> 3
2: 1 -> 5 -> 4 -> 3
3: 1 -> 2 -> 4
4: 1 -> 2 -> 5 -> 3
5: 2 -> 1 -> 4

Vertices degrees:
deg(1) = 4
deg(2) = 4
deg(3) = 3
deg(4) = 4
deg(5) = 3
```


