# Zadanie: Macierz incydencji grafu skierowanego


## Temat zadania
Napisanie programu, który dla grafu skierowanego:

- wczytuje dane wejściowe w postaci listy krawędzi,
- wyznacza liczbę wierzchołków,
- tworzy macierz incydencji,
- wypisuje macierz incydencji,
- wypisuje sąsiadów każdego wierzchołka.

---

## Treść zadania

Program ma wczytać graf skierowany zapisany w pliku tekstowym lub z wejścia standardowego w postaci listy krawędzi.

Format danych wejściowych:

- w pierwszej linii znajduje się liczba `k` oznaczająca liczbę krawędzi,
- w kolejnych `k` liniach znajdują się pary liczb całkowitych `u v`, które oznaczają krawędź skierowaną od wierzchołka `u` do wierzchołka `v`.

Na podstawie tych danych program ma:

1. odczytać wszystkie krawędzie,
2. określić liczbę wierzchołków,
3. zbudować macierz incydencji dla grafu skierowanego,
4. wypisać utworzoną macierz,
5. wypisać sąsiadów każdego wierzchołka.

---

## Założenia programu

W programie przyjęto następujące założenia:

- graf jest **skierowany**,
- wierzchołki są numerowane liczbami całkowitymi dodatnimi, zaczynając od `1`,
- liczba wierzchołków jest wyznaczana na podstawie największego numeru wierzchołka występującego w danych,
- każda kolumna macierzy incydencji odpowiada dokładnie jednej krawędzi,
- w macierzy incydencji przyjęto oznaczenia:
  - `-1` — początek krawędzi,
  - `1` — koniec krawędzi,
  - `0` — brak związku danego wierzchołka z daną krawędzią.

---

## Jak działa program

### 1. Wczytanie danych
Program odczytuje liczbę krawędzi `k`, a następnie zapisuje wszystkie krawędzie do wektora struktur `Edge`.

Przykład danych wejściowych:


5
1 2
2 3
1 3
3 4
4 2

## Przykładowe wyjście programu

### Macierz incydencji


-1 0 -1 0 0
1 -1 0 0 1
0 1 1 -1 0
0 0 0 1 -1

### Sąsiedzi wierzchołków

Neighbors of 1: 2 3
Neighbors of 2: 3
Neighbors of 3: 4
Neighbors of 4: 2

## Kompilacja

```bash

g++ main.cpp graph.cpp incidence_matrix.cpp -o graph_program