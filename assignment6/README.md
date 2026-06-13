# Wyszukiwanie elementu `k` w uporządkowanej macierzy 2D

## Cel programu

Program służy do wyszukiwania zadanej liczby całkowitej `k` w dwuwymiarowej tablicy liczb całkowitych o wymiarach `n × m`.

Przyjęto następujące założenia dotyczące macierzy:

- każdy wiersz jest posortowany niemalejąco,
- każda kolumna jest posortowana niemalejąco.

Dla podanej wartości `k` program wyznacza:

- **pierwsze wystąpienie** elementu metodą **iteracyjną**,
- **ostatnie wystąpienie** elementu metodą **iteracyjną**,
- **pierwsze wystąpienie** elementu metodą **rekurencyjną**,
- **ostatnie wystąpienie** elementu metodą **rekurencyjną**.

Jeżeli szukany element nie występuje w macierzy, program wypisuje odpowiedni komunikat.

---

## Zasada działania programu

Program rozpoczyna działanie od wczytania:

1. liczby zestawów danych,
2. dla każdego zestawu:
   - liczby wierszy `n`,
   - liczby kolumn `m`,
   - elementów macierzy,
   - wartości `k`, którą należy odnaleźć.

Po wczytaniu danych dla każdego zestawu program uruchamia cztery niezależne procedury wyszukiwania i wypisuje wyniki ich działania.

---

## Zastosowane podejście

W programie wykorzystano fakt, że **każdy wiersz macierzy jest posortowany**.  
Dzięki temu zamiast sprawdzać każdy element osobno, w każdym wierszu zastosowano **wyszukiwanie binarne**, co znacząco przyspiesza działanie programu.

### Wersja iteracyjna
- macierz jest przeszukiwana wiersz po wierszu,
- w każdym wierszu wykonywane jest **iteracyjne wyszukiwanie binarne**.

### Wersja rekurencyjna
- kolejne wiersze macierzy są przeszukiwane rekurencyjnie,
- w każdym wierszu wykonywane jest **rekurencyjne wyszukiwanie binarne**.

---

## Struktura programu

Program został podzielony na trzy pliki:

- **`main.cpp`** – odpowiada za wczytywanie danych, wywoływanie funkcji i wypisywanie wyników,
- **`search.h`** – zawiera deklaracje struktur oraz funkcji,
- **`search.cpp`** – zawiera definicje funkcji wyszukujących.

Taki podział zwiększa przejrzystość kodu i ułatwia jego rozwijanie.

---

## Opis wykorzystanych elementów

### Struktura `Result`

Struktura `Result` przechowuje wynik wyszukiwania i zawiera trzy pola:

- `found` – informacja, czy element został znaleziony,
- `row` – numer wiersza,
- `column` – numer kolumny.

---

## Opis funkcji

### Funkcje iteracyjne

#### `f_findFirstInRow`
Funkcja wykonuje iteracyjne wyszukiwanie binarne w jednym wierszu i zwraca pozycję **pierwszego wystąpienia** elementu `k`.

#### `f_findLastInRow`
Funkcja wykonuje iteracyjne wyszukiwanie binarne w jednym wierszu i zwraca pozyję **ostatniego wystąpienia** elementu `k`.

#### `f_iterativeFirst`
Funkcja przeszukuje macierz **od pierwszego do ostatniego wiersza** i zwraca **pierwsze wystąpienie** szukanego elementu.

#### `f_iterativeLast`
Funkcja przeszukuje macierz **od ostatniego do pierwszego wiersza** i zwraca **ostatnie wystąpienie** szukanego elementu.

---

### Funkcje rekurencyjne

#### `f_recFindFirstInRow`
Funkcja rekurencyjnie wykonuje wyszukiwanie binarne w jednym wierszu i odnajduje **pierwsze wystąpienie** elementu `k`.

#### `f_recMatrixFirst`
Funkcja rekurencyjnie przeszukuje kolejne wiersze macierzy **od góry do dołu**.

#### `f_recursiveFirst`
Funkcja uruchamia rekurencyjne wyszukiwanie **pierwszego wystąpienia** elementu w całej macierzy.

#### `f_recFindLastInRow`
Funkcja rekurencyjnie wykonuje wyszukiwanie binarne w jednym wierszu i odnajduje **ostatnie wystąpienie** elementu `k`.

#### `f_recMatrixLast`
Funkcja rekurencyjnie przeszukuje kolejne wiersze macierzy **od dołu do góry**.

#### `f_recursiveLast`
Funkcja uruchamia rekurencyjne wyszukiwanie **ostatniego wystąpienia** elementu w całej macierzy.

---

### Funkcja główna

#### `main`
Funkcja `main` odpowiada za:

- wczytanie danych wejściowych,
- utworzenie macierzy,
- wywołanie wszystkich funkcji wyszukujących,
- wypisanie wyników na ekran.

---

## Złożoność obliczeniowa

Wyszukiwanie w jednym wierszu realizowane jest za pomocą wyszukiwania binarnego, dlatego jego złożoność czasowa wynosi:

- **`O(log m)`**

Ponieważ w najgorszym przypadku przeszukiwane są wszystkie `n` wiersze, całkowita złożoność programu wynosi:

- **`O(n log m)`**

Jest to rozwiązanie znacznie efektywniejsze niż liniowe sprawdzanie wszystkich elementów macierzy.

---

## Kompilacja programu

Program można skompilować za pomocą kompilatora `g++` poleceniem:

```bash
g++ main.cpp search.cpp -o program