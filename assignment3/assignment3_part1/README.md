# Laboratorium 3 – Metody Programowania

## Opis zadania
Celem zadania było napisanie programu działającego na uporządkowanej niemalejąco tablicy liczb całkowitych. Program dla każdego zestawu danych realizuje trzy operacje:

1. **Obliczanie liczby wystąpień zadanej wartości**  
   Zostało zrealizowane w pesymistycznej złożoności O(log n) przy użyciu dwóch wyszukiwań binarnych:
   - pierwszego elementu `>= x`
   - pierwszego elementu `> x`

2. **Wyszukiwanie indeksu elementu równego zadanej wartości metodą interpolacyjną**  
   Zastosowano klasyczne wyszukiwanie interpolacyjne
   Jeżeli wartość nie występuje w tablicy, zwracane jest `-1`

3. **Usuwanie duplikatów**  
   Duplikaty są usuwane w miejscu, bez tworzenia dodatkowej tablicy pomocniczej, w czasie O(n).

## Struktura programu
Program został podzielony na pliki:
- `main.cpp` – obsługa wejścia/wyjścia
- `algorithms.h` – deklaracje funkcji
- `algorithms.cpp` – implementacja algorytmów

## Zastosowane funkcje
- `f_findFirstNotLess(...)`
- `f_findFirstGreater(...)`
- `f_countOccurrences(...)`
- `f_interpolationSearch(...)`
- `f_removeDuplicates(...)`

## Uwagi
- Tablica wejściowa jest uporządkowana niemalejąco.
- Przy wielokrotnym wystąpieniu tej samej wartości wyszukiwanie interpolacyjne może zwrócić **dowolny poprawny indeks** jednego z tych wystąpień.
- Po usunięciu duplikatów wypisywane jest maksymalnie 200 pierwszych elementów, po 50 w jednym wierszu.

## Kompilacja
```bash
g++ -std=c++17 -O2 main.cpp algorithms.cpp -o lab3