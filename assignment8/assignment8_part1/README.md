# Program 01 — Ogólny problem plecakowy

## 1. Cel programu

Celem programu jest rozwiązanie **ogólnego problemu plecakowego** przy użyciu **programowania dynamicznego**.

Program wybiera takie przedmioty, aby:

- całkowita masa przedmiotów nie przekroczyła pojemności plecaka,
- całkowita wartość przedmiotów była jak największa,
- każdy typ przedmiotu mógł zostać użyty dowolną liczbę razy.

Oznacza to, że jest to wersja problemu plecakowego typu **unbounded knapsack**, czyli problem plecakowy z nieograniczoną liczbą kopii każdego przedmiotu.

---

## 2. Struktura projektu

Program został podzielony na kilka plików tematycznych:

```text
main.cpp
items.h
knapsack.h
knapsack.cpp
input.txt
```

Taki podział ułatwia czytelność programu i rozdziela odpowiedzialności poszczególnych części kodu.

---

## 3. Opis plików

### `item.h`

Plik `items.h` zawiera definicję struktury `Item`.

Struktura przechowuje informacje o jednym przedmiocie:

```cpp
std::string name;
int mass;
int value;
```

Znaczenie pól:

- `name` — nazwa przedmiotu,
- `mass` — masa przedmiotu,
- `value` — wartość przedmiotu.

W tym pliku znajdują się również deklaracje oraz definicje konstruktorów struktury `Item`.

Konstruktor domyślny tworzy pusty przedmiot:

```cpp
Item::Item()
```

Konstruktor z parametrami tworzy przedmiot na podstawie podanej nazwy, masy i wartości:

```cpp
Item::Item(std::string itemName, int itemMass, int itemValue)
```

Dzięki temu w programie można łatwo tworzyć obiekty reprezentujące przedmioty wczytane z pliku.

---

### `knapsack.h`

Plik `knapsack.h` zawiera deklarację klasy `Knapsack`.

Klasa ta odpowiada za:

- przechowywanie pojemności plecaka,
- przechowywanie listy przedmiotów,
- utworzenie tablic dynamicznych `P` i `Q`,
- rozwiązanie problemu plecakowego,
- wypisanie wyników.

Najważniejsze pola klasy:

```cpp
int capacity;
std::vector<Item> items;
std::vector<std::vector<int>> P;
std::vector<std::vector<int>> Q;
```

Znaczenie tablic:

- `P[i][j]` — najlepsza możliwa wartość plecaka o pojemności `j`, gdy można używać pierwszych `i` typów przedmiotów,
- `Q[i][j]` — numer przedmiotu wybranego w ostatnim kroku dla wartości zapisanej w `P[i][j]`.

---

### `knapsack.cpp`

Plik `knapsack.cpp` zawiera definicje metod klasy `Knapsack`.

To tutaj znajduje się główny algorytm programowania dynamicznego, funkcje służące do wypisywania danych z tablic `P` i `Q`, funkcja wypisująca wszystkie przedmioty z ich wartościami oraz funkcja, która wypisuje największą uzyskaną wartość.

---

### `main.cpp`

Plik `main.cpp` odpowiada za uruchomienie programu.

Wykonuje następujące kroki:

1. Otwiera plik `input.txt`.
2. Wczytuje pojemność plecaka.
3. Wczytuje listę przedmiotów.
4. Sprawdza podstawowe błędy danych wejściowych.
5. Tworzy obiekt klasy `Knapsack`.
6. Wywołuje algorytm rozwiązujący problem.
7. Wypisuje przedmioty, tablice `P`, `Q` oraz najlepszy wynik.

---

## 4. Format danych wejściowych

Dane wejściowe znajdują się w pliku `input.txt`.

Pierwsza linia zawiera pojemność plecaka:

```text
10
```

Każda kolejna linia zawiera dane jednego przedmiotu:

```text
nazwa wartość masa
```

Przykład:

```text
10
Koszula 75 7
Spodnie 150 8
Bluza 250 6
Czapka 35 4
Szalik 10 3
Buty 100 9
```

W tym przykładzie pojemność plecaka wynosi `10`.

---

## 5. Najważniejsza idea algorytmu

Algorytm używa programowania dynamicznego.

Dla każdego przedmiotu `i` oraz każdej pojemności plecaka `j` program sprawdza dwie możliwości:

### Opcja 1 — nie bierzemy aktualnego przedmiotu

Wtedy najlepszy wynik jest taki sam jak w poprzednim wierszu:

```cpp
P[i - 1][j]
```

Oznacza to, że ignorujemy aktualny przedmiot i korzystamy tylko z poprzednich przedmiotów.

---

### Opcja 2 — bierzemy aktualny przedmiot

Jeżeli masa aktualnego przedmiotu mieści się w aktualnej pojemności plecaka, można go dodać:

```cpp
P[i][j - currMass] + currVal
```

Używane jest `P[i][...]`, a nie `P[i - 1][...]`, ponieważ w ogólnym problemie plecakowym ten sam przedmiot można wybrać wiele razy.

---

## 6. Wzór dynamiczny

Dla każdego `i` i `j` program wybiera większą wartość:

```cpp
P[i][j] = max(
    P[i - 1][j],
    P[i][j - currMass] + currVal
)
```

Druga opcja jest możliwa tylko wtedy, gdy:

```cpp
currMass <= j
```

Jeżeli przedmiot nie mieści się w plecaku, program przepisuje wartość z poprzedniego wiersza:

```cpp
P[i][j] = P[i - 1][j]
```

---

## 7. Opis działania funkcji

### `Knapsack::Knapsack(int backpackCap, std::vector<Item> itemList)`

Konstruktor klasy `Knapsack`.

Zapisuje pojemność plecaka i listę przedmiotów, a następnie tworzy tablice `P` i `Q`.

Tablice mają rozmiar:

```text
liczba_przedmiotów + 1
pojemność_plecaka + 1
```

Dodatkowy wiersz i dodatkowa kolumna są potrzebne dla przypadku bazowego, czyli sytuacji, gdy:

- nie mamy żadnych przedmiotów,
- pojemność plecaka wynosi `0`.

---

### `Knapsack::solve()`

Najważniejsza funkcja programu.

Wypełnia tablice `P` i `Q`.

Działanie funkcji:

1. Przechodzi po wszystkich przedmiotach.
2. Dla każdego przedmiotu przechodzi po wszystkich możliwych pojemnościach plecaka.
3. Sprawdza, czy aktualny przedmiot mieści się w aktualnej pojemności.
4. Oblicza wynik bez aktualnego przedmiotu.
5. Oblicza wynik z aktualnym przedmiotem.
6. Porównuje oba wyniki.
7. Lepszy wynik zapisuje w tablicy `P`.
8. Informację o wybranym przedmiocie zapisuje w tablicy `Q`.

Fragment odpowiedzialny za decyzję:

```cpp
if(optionWithItem > optionWithoutItem){
    P[i][j] = optionWithItem;
    Q[i][j] = i;
}else{
    P[i][j] = optionWithoutItem;
    Q[i][j] = Q[i - 1][j];
}
```

Jeżeli wybranie aktualnego przedmiotu daje lepszą wartość, program zapisuje tę wartość i numer przedmiotu.

Jeżeli lepszy lub równy wynik był już wcześniej dostępny, program kopiuje wartość z poprzedniego wiersza.

---

### `Knapsack::printItems() const`

Funkcja wypisuje wszystkie przedmioty wczytane z pliku.

Dla każdego przedmiotu wypisywane są:

- numer przedmiotu,
- nazwa,
- masa,
- wartość.

---

### `Knapsack::printTableP() const`

Funkcja wypisuje tablicę `P`.

Tablica `P` pokazuje najlepsze wartości dla kolejnych pojemności plecaka i kolejnych zestawów dostępnych przedmiotów.

Wiersz `i` oznacza, że można korzystać z pierwszych `i` przedmiotów.

Kolumna `j` oznacza pojemność plecaka równą `j`.

---

### `Knapsack::printTableQ() const`

Funkcja wypisuje tablicę `Q`.

Tablica `Q` pokazuje, który przedmiot został wybrany jako ostatni przy uzyskaniu wartości zapisanej w tablicy `P`.

Dzięki tej tablicy można później odtworzyć, z jakich przedmiotów składa się najlepsze rozwiązanie.

---

### `Knapsack::printBestValue() const`

Funkcja wypisuje najlepszą możliwą wartość plecaka.

Wartość ta znajduje się w ostatniej komórce tablicy `P`:

```cpp
P[n][capacity]
```

gdzie:

- `n` — liczba przedmiotów,
- `capacity` — pojemność plecaka.

---

## 8. Przykładowy wynik działania programu

Dla danych wejściowych:

```text
10
Koszula 75 7
Spodnie 150 8
Bluza 250 6
Czapka 35 4
Szalik 10 3
Buty 100 9
```

program wypisuje:

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

Najlepsza wartość wynosi `285`.

Wynik ten jest możliwy do uzyskania dla plecaka o pojemności `10`.

---

## 9. Kompilacja programu

Program można skompilować poleceniem:

```bash
g++ main.cpp knapsack.cpp -o program
```

Uruchomienie programu:

```bash
./program
```

---

## 10. Podsumowanie

Program rozwiązuje ogólny problem plecakowy przy pomocy programowania dynamicznego.

Najważniejszą częścią programu jest tablica `P`, która przechowuje najlepsze wartości dla kolejnych pojemności plecaka.

Tablica `Q` przechowuje informację o ostatnio wybranym przedmiocie, co pozwala analizować sposób budowania rozwiązania.

Dzięki zastosowaniu programowania dynamicznego program nie sprawdza wszystkich możliwych kombinacji ręcznie, tylko stopniowo buduje rozwiązanie na podstawie wcześniej obliczonych wyników.
