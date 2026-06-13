# Projekt: Porównanie metod sortowania tablic

## Autorzy projektu

Projekt został wykonany w dwuosobowym zespole:

* **Daniel Marmuliak** — implementacja sortowania bąbelkowego wahadłowego `Shaker sort`, przygotowanie głównej struktury programu, obsługa menu, generowanie danych, zapis wyników do pliku oraz integracja całego projektu.
* **Bartosz Zmucha** — implementacja sortowania szybkiego `Quick sort` w wariantach `Lomuto` i `Hoare` oraz implementacja sortowania przez kopcowanie `Heap sort`.

---

## Cel projektu

Celem projektu było napisanie programu w języku C++, który umożliwia porównanie wybranych algorytmów sortowania pod względem liczby wykonanych porównań oraz przestawień elementów.

W programie zostały zaimplementowane następujące metody sortowania:

1. **Shaker sort** — sortowanie bąbelkowe wahadłowe.
2. **Quick sort z podziałem Lomuto**.
3. **Quick sort z podziałem Hoare’a**.
4. **Heap sort** — sortowanie przez kopcowanie.

Program pozwala sprawdzić działanie algorytmów dla tablic o różnych długościach i różnych typach uporządkowania danych.

---

## Struktura projektu

Projekt został podzielony na kilka plików, aby kod był czytelniejszy i łatwiejszy do rozwijania.

```text
ProjektSortowanie/
│
├── main.cpp
├── SortStats.h
├── cTablica.h
├── cTablica.cpp
├── cSortTablicy.h
└── cSortTablicy.cpp
```

### Opis plików

#### `main.cpp`

Plik zawiera funkcję główną programu. Tworzony jest w nim obiekt klasy `cSortTablicy`, a następnie uruchamiane jest menu programu.

#### `SortStats.h`

Plik zawiera strukturę `SortStats`, która przechowuje statystyki sortowania:

* liczbę porównań,
* liczbę przestawień.

#### `cTablica.h`

Plik nagłówkowy klasy `cTablica`. Klasa ta przechowuje tablicę oraz deklaracje metod sortowania.

#### `cTablica.cpp`

Plik zawiera implementacje algorytmów sortowania:

* `shakerSort()`,
* `quickSortLomuto()`,
* `quickSortHoare()`,
* `heapSort()`.

Znajdują się tutaj również funkcje pomocnicze, takie jak `partitionLomuto()`, `partitionHoare()`, `heapify()` oraz `swapElements()`.

#### `cSortTablicy.h`

Plik nagłówkowy klasy `cSortTablicy`. Klasa ta odpowiada za obsługę użytkownika, menu programu, generowanie tablic i uruchamianie testów.

#### `cSortTablicy.cpp`

Plik zawiera implementację menu programu, generowania tablic, wyboru metody sortowania oraz zapisu wyników do pliku tekstowego.

---

## Opis działania programu

Program działa w trybie konsolowym. Po uruchomieniu wyświetlane jest menu:

```text
===== MENU =====
1. Wprowadz tablice z klawiatury
2. Wygeneruj tablice
3. Pokaz aktualna tablice
4. Posortuj aktualna tablice
5. Wykonaj testy i zapisz wyniki do pliku
0. Koniec programu
```

Użytkownik może samodzielnie wprowadzić tablicę z klawiatury albo wygenerować ją automatycznie.

Program umożliwia wygenerowanie czterech typów tablic:

1. tablica losowa,
2. tablica posortowana rosnąco,
3. tablica posortowana malejąco,
4. tablica częściowo uporządkowana.

Następnie użytkownik może wybrać metodę sortowania. Po zakończeniu sortowania program wyświetla:

* tablicę przed sortowaniem,
* tablicę po sortowaniu,
* nazwę użytej metody,
* liczbę porównań,
* liczbę przestawień.

---

## Automatyczne testy

Program posiada opcję wykonania testów automatycznych. Po wybraniu opcji:

```text
5. Wykonaj testy i zapisz wyniki do pliku
```

program wykonuje sortowania dla tablic o długościach:

```text
100
1000
1000000
```

Dla każdej długości generowane są cztery typy tablic:

```text
losowa
posortowana rosnąco
posortowana malejąco
częściowo uporządkowana
```

Następnie każda tablica jest sortowana czterema metodami:

```text
Shaker sort
Quick sort Lomuto
Quick sort Hoare
Heap sort
```

Wyniki są zapisywane do pliku:

```text
wyniki_sortowania.txt
```

W pliku wynikowym znajduje się tabela zawierająca:

* nazwę metody sortowania,
* długość tablicy,
* rodzaj tablicy,
* liczbę porównań,
* liczbę przestawień.

Na końcu pliku dopisane są krótkie wnioski z przeprowadzonych testów.

---

## Liczenie porównań i przestawień

Do przechowywania wyników została wykorzystana struktura:

```cpp
struct SortStats {
    long long comparisons = 0;
    long long swaps = 0;
};
```

Pole `comparisons` przechowuje liczbę porównań wykonanych podczas sortowania.

Pole `swaps` przechowuje liczbę przestawień elementów.

Zastosowano typ `long long`, ponieważ przy dużych tablicach liczba operacji może być bardzo duża.

---

## Opis zaimplementowanych algorytmów

### Shaker sort

`Shaker sort` jest odmianą sortowania bąbelkowego. W zwykłym sortowaniu bąbelkowym tablica jest przeglądana tylko w jednym kierunku. W sortowaniu wahadłowym przejścia wykonywane są w dwóch kierunkach:

1. od lewej do prawej,
2. od prawej do lewej.

Podczas przejścia od lewej do prawej największy element przesuwa się na koniec nieposortowanej części tablicy. Podczas przejścia od prawej do lewej najmniejszy element przesuwa się na początek.

Algorytm działa dobrze dla małych lub prawie posortowanych tablic, ale dla dużych tablic jest mało wydajny.

Złożoność czasowa:

```text
najlepszy przypadek: O(n)
średni przypadek:    O(n²)
najgorszy przypadek: O(n²)
```

Złożoność pamięciowa:

```text
O(1)
```

---

### Quick sort z podziałem Lomuto

Quick sort jest algorytmem typu „dziel i zwyciężaj”. Wariant Lomuto wybiera pivot, a następnie przenosi elementy mniejsze lub równe pivotowi na lewą stronę tablicy. Po zakończeniu podziału pivot znajduje się na swojej właściwej pozycji.

W projekcie pivot jest wybierany jako środkowy element zakresu, a następnie przenoszony na koniec, aby można było zastosować schemat Lomuto.

Zalety wariantu Lomuto:

* prosty do zrozumienia,
* łatwy do zaimplementowania.

Wady:

* może wykonywać więcej przestawień niż wariant Hoare’a.

Złożoność czasowa:

```text
najlepszy przypadek: O(n log n)
średni przypadek:    O(n log n)
najgorszy przypadek: O(n²)
```

---

### Quick sort z podziałem Hoare’a

Wariant Hoare’a również wykorzystuje pivot, ale działa inaczej niż Lomuto. Używa dwóch indeksów:

* jeden przesuwa się od lewej strony,
* drugi przesuwa się od prawej strony.

Indeksy szukają elementów, które znajdują się po niewłaściwej stronie pivota. Jeżeli takie elementy zostaną znalezione, są zamieniane miejscami.

Wariant Hoare’a zazwyczaj wykonuje mniej przestawień niż wariant Lomuto.

Ważna różnica polega na tym, że funkcja podziału Hoare’a nie zwraca dokładnej pozycji pivota, tylko indeks podziału tablicy.

Złożoność czasowa:

```text
najlepszy przypadek: O(n log n)
średni przypadek:    O(n log n)
najgorszy przypadek: O(n²)
```

---

### Heap sort

Heap sort wykorzystuje strukturę kopca. W projekcie zastosowano kopiec maksymalny, w którym największy element znajduje się na początku tablicy.

Algorytm składa się z dwóch głównych etapów:

1. zbudowanie kopca maksymalnego,
2. wielokrotne przenoszenie największego elementu na koniec tablicy.

Po każdym przeniesieniu największego elementu rozmiar kopca jest zmniejszany, a funkcja `heapify()` przywraca własność kopca.

Heap sort jest bardzo stabilny pod względem złożoności czasowej, ponieważ w każdym przypadku działa w czasie `O(n log n)`.

Złożoność czasowa:

```text
najlepszy przypadek: O(n log n)
średni przypadek:    O(n log n)
najgorszy przypadek: O(n log n)
```

Złożoność pamięciowa:

```text
O(1)
```

---

## Klasa `cTablica`

Klasa `cTablica` odpowiada za przechowywanie tablicy i wykonywanie algorytmów sortowania.

Najważniejsze pole klasy:

```cpp
std::vector<int> data;
```

Pole `data` przechowuje liczby znajdujące się w tablicy.

Najważniejsze metody klasy:

```cpp
SortStats shakerSort();
SortStats quickSortLomuto();
SortStats quickSortHoare();
SortStats heapSort();
```

Każda metoda sortuje tablicę i zwraca strukturę `SortStats` z liczbą porównań i przestawień.

W klasie znajdują się również funkcje pomocnicze:

```cpp
void swapElements(int i, int j, SortStats& stats);
int partitionLomuto(int low, int high, SortStats& stats);
int partitionHoare(int low, int high, SortStats& stats);
void heapify(int n, int i, SortStats& stats);
```

Funkcja `swapElements()` zamienia dwa elementy miejscami i zwiększa licznik przestawień.

Funkcje `partitionLomuto()` i `partitionHoare()` odpowiadają za podział tablicy w algorytmie quick sort.

Funkcja `heapify()` odpowiada za przywrócenie własności kopca w algorytmie heap sort.

---

## Klasa `cSortTablicy`

Klasa `cSortTablicy` odpowiada za obsługę całego programu od strony użytkownika.

Najważniejsze zadania tej klasy:

* wyświetlanie menu,
* wczytywanie tablicy z klawiatury,
* generowanie tablic,
* wybór metody sortowania,
* uruchamianie testów,
* zapis wyników do pliku.

Najważniejsze metody klasy:

```cpp
void menu();
void inputFromKeyboard();
void generateFromKeyboard();
void sortCurrentArray();
void runBenchmark(const std::string& fileName);
```

Metoda `menu()` obsługuje główne menu programu.

Metoda `inputFromKeyboard()` pozwala wprowadzić tablicę ręcznie.

Metoda `generateFromKeyboard()` generuje tablicę na podstawie wyboru użytkownika.

Metoda `sortCurrentArray()` sortuje aktualną tablicę wybraną metodą.

Metoda `runBenchmark()` wykonuje testy automatyczne i zapisuje wyniki do pliku.

---

## Obsługa błędów

W programie zastosowano obsługę błędów z użyciem wyjątków.

Jeżeli użytkownik poda niepoprawną wartość, na przykład tekst zamiast liczby, program zgłasza wyjątek i wyświetla komunikat o błędzie.

Przykład:

```cpp
throw std::runtime_error("Podano nieprawidlowa liczbe");
```

Dzięki temu program nie kończy działania natychmiast po błędzie, tylko wraca do menu i pozwala użytkownikowi kontynuować pracę.

---

## Generowanie tablicy częściowo uporządkowanej

Jednym z typów danych testowych jest tablica częściowo uporządkowana.

Program najpierw tworzy tablicę posortowaną rosnąco, a następnie losowo wybiera około 10% indeksów. Wartości na tych indeksach są przestawiane między sobą.

Dzięki temu większość tablicy pozostaje uporządkowana, ale część elementów znajduje się na niewłaściwych pozycjach.

Pozwala to sprawdzić, jak algorytmy sortowania działają dla danych prawie posortowanych.

---

## Ważna informacja o sortowaniu `Shaker sort` dla 1 000 000 elementów

Sortowanie `Shaker sort` ma złożoność `O(n²)`, dlatego dla tablicy zawierającej `1 000 000` elementów może działać bardzo długo.

Z tego powodu w programie dodano pytanie:

```text
Czy uruchomic Shaker sort dla 1 000 000 elementow? [t/n]
```

Jeżeli użytkownik wybierze `n`, test zostanie pominięty, a w pliku wynikowym pojawi się informacja:

```text
Pominieto
```

Jest to rozwiązanie praktyczne, ponieważ uruchamianie algorytmu o złożoności `O(n²)` dla tak dużej liczby elementów może być bardzo czasochłonne.

---

## Kompilacja programu

Program można skompilować za pomocą kompilatora `g++`.

Przykładowa komenda:

```bash
g++ -std=c++17 main.cpp cTablica.cpp cSortTablicy.cpp -o sortowanie
```

Uruchomienie programu w systemie Linux lub macOS:

```bash
./sortowanie
```

Uruchomienie programu w systemie Windows:

```bash
sortowanie.exe
```

---

## Przykładowy przebieg działania programu

Po uruchomieniu programu użytkownik może wybrać opcję wygenerowania tablicy. Następnie podaje długość tablicy i wybiera jej typ.

Przykład:

```text
Podaj dlugosc tablicy: 10

Rodzaje tablic:
1. Losowa
2. Posortowana rosnaco
3. Posortowana malejaco
4. Czesciowo uporzadkowana

Wybierz rodzaj tablicy: 1
```

Następnie użytkownik może wybrać metodę sortowania:

```text
Metody sortowania:
1. Shaker sort
2. Quick sort Lomuto
3. Quick sort Hoare
4. Heap sort

Wybierz metode sortowania: 4
```

Program wyświetli tablicę przed i po sortowaniu oraz statystyki:

```text
Metoda: Heap sort
Liczba porownan: ...
Liczba przestawien: ...
```

---

## Wnioski

Na podstawie działania programu można zauważyć, że różne algorytmy sortowania mają różną efektywność w zależności od rodzaju danych wejściowych.

`Shaker sort` jest prosty do zrozumienia i implementacji, ale dla dużych tablic jest nieefektywny, ponieważ jego złożoność wynosi `O(n²)`.

`Quick sort` w obu wariantach zwykle działa bardzo szybko, szczególnie dla danych losowych. Wariant Hoare’a zazwyczaj wykonuje mniej przestawień niż wariant Lomuto.

`Heap sort` ma gwarantowaną złożoność `O(n log n)` w każdym przypadku, dlatego dobrze nadaje się do sortowania dużych tablic.

Rodzaj danych wejściowych ma duży wpływ na liczbę porównań i przestawień. Tablice losowe, rosnące, malejące i częściowo uporządkowane mogą dawać różne wyniki dla poszczególnych algorytmów.

Program pozwala porównać te różnice i zapisać wyniki w pliku tekstowym, co ułatwia analizę działania zaimplementowanych metod sortowania.
