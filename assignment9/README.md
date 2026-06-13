# Laboratorium 9 — Program 01

## Temat zadania

Program rozwiązuje problem plecakowy 0/1 za pomocą algorytmu z powrotami oraz metody ograniczeń, czyli `branch and bound`.

W zadaniu mamy 5 przedmiotów i plecak o pojemności `W = 19`. Każdy przedmiot ma:

- `p` — zysk / wartość,
- `w` — wagę,
- `p/w` — stosunek zysku do wagi.

Celem jest wybranie takich przedmiotów, aby nie przekroczyć pojemności plecaka i uzyskać jak największy zysk.

## Dane użyte w programie

| i | p | w | p/w |
|---|---:|---:|---:|
| 1 | 20 | 2 | 10 |
| 2 | 30 | 5 | 6 |
| 3 | 35 | 7 | 5 |
| 4 | 12 | 3 | 4 |
| 5 | 3 | 1 | 3 |

## Jak działa program

1. Program tworzy listę przedmiotów zgodnie z tabelą z zadania.
2. Przedmioty są sortowane malejąco według wartości `p/w`.
3. Algorytm buduje drzewo decyzji.
4. Dla każdego przedmiotu sprawdzane są dwie możliwości:
   - wziąć przedmiot do plecaka,
   - nie wziąć przedmiotu do plecaka.
5. Dla każdego węzła obliczana jest granica `bound`, czyli optymistyczny maksymalny zysk możliwy do uzyskania z tego miejsca drzewa.
6. Jeżeli węzeł nie może dać lepszego wyniku niż aktualne najlepsze rozwiązanie, program go odcina.
7. Na końcu program zapisuje najlepszy wynik do pliku `wynik.txt`.

## Wzór na granicę

Granica jest liczona na podstawie idei plecaka ułamkowego. Program dodaje całe kolejne przedmioty, dopóki mieszczą się w plecaku. Jeśli następny przedmiot już się nie mieści, program dodaje tylko jego możliwą ułamkową część do obliczenia teoretycznej granicy.

W uproszczeniu:

```text
bound = aktualny_zysk + zysk_kolejnych_przedmiotów + wolne_miejsce * (p/w następnego przedmiotu)
```

Dzięki temu wiemy, czy warto dalej rozwijać dany węzeł drzewa.

## Struktura plików

```text
lab9_Danylo_Marmulyak/
│
├── main.cpp                          # główny plik programu
├── Item.h                            # struktura jednego przedmiotu
├── KnapsackSolver.h                  # deklaracja klasy rozwiązującej problem
├── KnapsackSolver.cpp                # implementacja algorytmu
└── README.md                         # opis zadania
```

## Kompilacja

Program można skompilować poleceniem:

```bash
g++ main.cpp KnapsackSolver.cpp -o program01
```

## Uruchomienie

Po kompilacji należy uruchomić program:

```bash
./program01
```

Program utworzy plik:

```text
wynik.txt
```

W pliku `wynik.txt` znajdują się wszystkie kroki działania algorytmu: aktualny węzeł, zysk, waga, obliczona granica, decyzje o dodaniu albo pominięciu przedmiotu oraz wynik końcowy.

## Wynik dla danych z zadania

Dla podanych danych najlepszym rozwiązaniem jest wzięcie wszystkich przedmiotów:

```text
Przedmioty: 1, 2, 3, 4, 5
Łączna waga: 18
Maksymalny zysk: 100
Pozostała pojemność plecaka: 1
```

Wynik jest poprawny, ponieważ suma wag wszystkich przedmiotów wynosi `18`, a pojemność plecaka wynosi `19`, więc wszystkie przedmioty mieszczą się w plecaku.

Do wykonania zadania użyliśmy:

- rekurencji,
- algorytmu z powrotami,
- metody `branch and bound`,
- sortowania przedmiotów według `p/w`,

## Krótkie podsumowanie

Program sprawdza różne kombinacje przedmiotów, ale nie musi analizować całego drzewa do końca. Jeżeli z obliczonej granicy wynika, że dany węzeł nie da lepszego wyniku niż obecnie najlepszy, to dalsze sprawdzanie tej gałęzi jest pomijane. Dzięki temu algorytm działa czytelnie i pokazuje, jak można ograniczyć liczbę sprawdzanych przypadków.
