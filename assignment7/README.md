# Zadanie: Generator liczb pseudolosowych

## Opis zadania

Program generuje liczby pseudolosowe za pomocą dwóch metod:

1. **Liniowej metody kongruencyjnej — LCG**
2. **Addytywnej metody kongruencyjnej**

Użytkownik po uruchomieniu programu wybiera metodę generowania liczb, podaje wymagane dane wejściowe, a następnie program zapisuje wygenerowany ciąg liczb do pliku tekstowego w postaci jednej kolumny.

---

## Struktura plików

- `main.cpp` – uruchomienie programu, wybór metody i obsługa danych wejściowych
- `lcg.h` – deklaracje funkcji związanych z liniową metodą kongruencyjną
- `lcg.cpp` – definicje funkcji związanych z liniową metodą kongruencyjną
- `additive.h` – deklaracje funkcji związanych z addytywną metodą kongruencyjną
- `additive.cpp` – definicje funkcji związanych z addytywną metodą kongruencyjną
- `utils.h` – deklaracje funkcji pomocniczych
- `utils.cpp` – definicje funkcji pomocniczych

---

## Jak działa program

### 1. Wybór metody

Po uruchomieniu programu użytkownik wybiera jedną z dwóch metod:

```text
1. Linear Congruential Method
2. Additive Congruential Method
```

Dla opcji `1` program uruchamia generator oparty na **liniowej metodzie kongruencyjnej**.

Dla opcji `2` program uruchamia generator oparty na **addytywnej metodzie kongruencyjnej**.

---

# Liniowa metoda kongruencyjna — LCG

## Opis metody

Liniowa metoda kongruencyjna generuje kolejne liczby pseudolosowe na podstawie wzoru:

```text
X(n+1) = (a * X(n) + c) mod m
```

gdzie:

- `X(n)` – poprzednia liczba pseudolosowa,
- `X(n+1)` – następna liczba pseudolosowa,
- `a` – mnożnik,
- `c` – przyrost,
- `m` – moduł,
- `seed` / `x0` – wartość początkowa generatora.

Generator LCG jest deterministyczny, co oznacza, że dla tych samych wartości `seed`, `a`, `c` i `m` zawsze wygeneruje taki sam ciąg liczb.

---

## Dane wejściowe dla LCG

Program wczytuje:

- `n` – liczbę wartości do wygenerowania,
- `seed` – wartość początkową generatora,
- `xmax` – maksymalną wartość pseudolosową.

Przykład:

```text
How many numbers do you want to generate?: 6
Enter seed: 5
Enter max value: 12
```

Dla `xmax = 12` program generuje liczby z przedziału:

```text
<1, 12>
```

---

## Założenia dla LCG

Program sprawdza następujące warunki:

```text
n >= 0
m > 0
0 <= a < m
0 <= c < m
0 <= x0 < m
```

gdzie:

- `n` – liczba generowanych wartości,
- `m` – moduł,
- `a` – mnożnik,
- `c` – przyrost,
- `x0` – wartość początkowa generatora, czyli `seed`.

---

## Dobór współczynników LCG

Współczynniki generatora są obliczane automatycznie na podstawie wartości `xmax`.

### Obliczenie `m`

Funkcja:

```cpp
int f_lcgCalculateM(int xmax);
```

oblicza moduł według wzoru:

```text
m = xmax + 1
```
Dzięki temu generator wewnętrznie pracuje na wartościach z zakresu:

```text
0 ... 12
```

Ponieważ wynik końcowy ma należeć do przedziału `<1, xmax>`, wartość `0` jest pomijana podczas zapisywania wyników.

---

### Obliczenie `a`

Funkcja:

```cpp
int f_lcgCalculateA(int m);
```
odpowiada za wybór mnożnika `a`.

Program sprawdza kolejne wartości `a` z zakresu:

```text
2 <= a < m
```

Dla każdej wartości `a` obliczany jest okres `lambda`.

Okres jest wyznaczany przez funkcję:

```cpp
int f_lcgFindLambda(int a, int m);
```

Funkcja szuka najmniejszej wartości `lambda`, dla której spełniony jest warunek:

```text
a^lambda mod m = 1
```
Program wybiera taką wartość `a`, dla której okres `lambda` jest największy.

Jeżeli kilka wartości `a` ma taki sam maksymalny okres, wybierana jest największa wartość `a`.

Przykład dla:

```text
xmax = 12
m = 13
```

program może wybrać:

```text
a = 11
```

---

### Obliczenie `c`

Funkcja:

```cpp
int f_lcgCalculateC(int m);
```
odpowiada za wybór przyrostu `c`.

Program wybiera największą wartość `c`, która spełnia warunek:

```text
NWD(c, m) = 1
```

Do obliczenia największego wspólnego dzielnika używana jest funkcja:

```cpp
int f_findGCD(int a, int b);
```

Funkcja `f_findGCD` wykorzystuje algorytm Euklidesa.

Przykład:

```text
m = 13
c = 12
```

Liczby `12` i `13` są względnie pierwsze, dlatego `c = 12` może zostać użyte jako przyrost.

---

## Funkcja generująca LCG

Za wygenerowanie ciągu liczb metodą LCG odpowiada funkcja:

```cpp
std::vector<int> f_generateLCG(int n, int seed, int xmax);
```

Funkcja wykonuje następujące kroki:

1. Tworzy pusty wektor na wygenerowane liczby.
2. Sprawdza poprawność danych wejściowych.
3. Oblicza współczynniki `m`, `a` i `c`.
4. Sprawdza, czy `seed`, `a` i `c` znajdują się w poprawnym zakresie.
5. Ustawia wartość początkową:

```text
x = seed
```

6. Generuje kolejne wartości według wzoru:

```text
x = (a * x + c) mod m
```

7. Pomija wartość `0`, aby wynik należał do przedziału `<1, xmax>`.
8. Dodaje wygenerowane liczby do wektora.
9. Zwraca wektor z wynikami.

---

## Pomocnicza funkcja LCG

W programie znajduje się również funkcja:

```cpp
std::vector<int> f_generateLCGRaw(int n, int seed, int m);
```

Jest to pomocnicza wersja generatora LCG.

Różni się od `f_generateLCG` tym, że nie pomija wartości `0`.

Generuje liczby z zakresu:

```text
0 <= x < m
```

Ta funkcja jest wykorzystywana w addytywnej metodzie kongruencyjnej do utworzenia początkowej tablicy wartości.

---

# Addytywna metoda kongruencyjna

## Opis metody

Addytywna metoda kongruencyjna generuje liczby na podstawie wcześniej przygotowanej tablicy wartości.

Kolejna liczba powstaje przez dodanie dwóch elementów tablicy i wykonanie operacji modulo.

Podstawowy wzór:

```text
Y[k] = (Y[j] + Y[k]) mod m
```

gdzie:

- `Y` – tablica wartości generatora,
- `j` – pierwszy indeks,
- `k` – drugi indeks,
- `m` – moduł.

Po obliczeniu nowej wartości aktualizowana jest komórka `Y[k]`.

Następnie indeksy `j` i `k` są zmniejszane. Jeżeli któryś indeks spadnie poniżej zera, zostaje przeniesiony na koniec tablicy.

---

## Dane wejściowe dla metody addytywnej

Program wczytuje:

- `n` – liczbę wartości do wygenerowania oraz rozmiar tablicy początkowej,
- `m` – moduł,
- `seed` – wartość początkową dla pomocniczego generatora LCG.

Przykład:

```text
Enter n: 6
Enter modulus m: 8
Enter seed for initial LCG table: 5
```

---

## Założenia dla metody addytywnej

Program sprawdza następujące warunki:

```text
n > 0
m > 0
0 <= seed < m
```

---

## Wybór pary indeksów `(j, k)`

W metodzie addytywnej potrzebna jest para indeksów `(j, k)`.

W przykładzie laboratoryjnym dla:

```text
n = 6
m = 8
```

wybierana jest para:

```text
(2, 5)
```

W programie za wybór pary odpowiada funkcja:

```cpp
std::pair<int, int> choosePair(int n);
```

Dla `n = 6` funkcja zwraca:

```text
(2, 5)
```

Ponieważ w przykładzie z laboratorium tablica jest indeksowana od `1`, a w C++ tablice są indeksowane od `0`, program zamienia indeksy w następujący sposób:

```text
j = 2 - 1 = 1
k = 5 - 1 = 4
```

---

## Tworzenie tablicy początkowej

Addytywna metoda kongruencyjna wymaga początkowej tablicy wartości.

W programie tablica ta jest generowana za pomocą wcześniej zaimplementowanego generatora LCG.

Odpowiada za to funkcja:

```cpp
std::vector<int> createInitialTable(int n, int m, int seed);
```

Funkcja wywołuje:

```cpp
f_generateLCGRaw(n, seed, m);
```

Dzięki temu powstaje tablica początkowa zawierająca wartości z zakresu:

```text
0 <= x < m
```

---

## Odwrócenie tablicy

Zgodnie z przykładem z laboratorium, po wygenerowaniu tablicy początkowej `X` tworzona jest tablica `Y`, która jest odwróconą wersją tablicy `X`.

Przykład:

```text
X = [2, 5, 1, 7, 4, 3]
Y = [3, 4, 7, 1, 5, 2]
```

Za odwrócenie tablicy odpowiada funkcja:

```cpp
std::vector<int> reverseTable(const std::vector<int>& x);
```

W implementacji używana jest funkcja:

```cpp
std::reverse(y.begin(), y.end());
```

---

## Funkcja generująca metodą addytywną

Za wygenerowanie ciągu liczb metodą addytywną odpowiada funkcja:

```cpp
std::vector<int> f_generateAdditive(int n, int m, int seed);
```

Funkcja wykonuje następujące kroki:

1. Tworzy pusty wektor na wygenerowane liczby.
2. Sprawdza poprawność danych wejściowych.
3. Wybiera parę indeksów `(j, k)`.
4. Zamienia indeksy z notacji od `1` na indeksy C++ od `0`.
5. Tworzy początkową tablicę `X` za pomocą LCG.
6. Odwraca tablicę `X`, tworząc tablicę `Y`.
7. Generuje kolejne liczby według wzoru:

```text
Y[k] = (Y[j] + Y[k]) mod m
```

8. Dodaje wartość `Y[k]` do wektora wynikowego.
9. Zmniejsza indeksy `j` i `k`.
10. Jeżeli indeks spadnie poniżej `0`, ustawia go na koniec tablicy.
11. Zwraca wektor z wygenerowanymi liczbami.

---

## Przykład działania metody addytywnej

Dla danych:

```text
n = 6
m = 8
pair = (2, 5)
```

po zamianie na indeksowanie C++:

```text
j = 1
k = 4
```

Jeżeli tablica `Y` ma postać:

```text
Y = [3, 4, 7, 1, 5, 2]
```

to pierwszy krok wygląda następująco:

```text
Y[k] = (Y[j] + Y[k]) mod m
Y[4] = (Y[1] + Y[4]) mod 8
Y[4] = (4 + 5) mod 8
Y[4] = 1
```

Po aktualizacji tablica wygląda tak:

```text
Y = [3, 4, 7, 1, 1, 2]
```

Następnie indeksy są zmniejszane:

```text
j = j - 1
k = k - 1
```

---

# Funkcje pomocnicze

## `f_findGCD`

```cpp
int f_findGCD(int a, int b);
```

Funkcja oblicza największy wspólny dzielnik dwóch liczb za pomocą algorytmu Euklidesa.

Jest używana przy wyborze współczynnika `c` w metodzie LCG.

---

## `f_validateN`

```cpp
bool f_validateN(int n);
```

Funkcja sprawdza poprawność liczby generowanych wartości.

Warunek dla LCG:

```text
n >= 0
```

W przypadku metody addytywnej dodatkowo wymagane jest:

```text
n > 0
```

ponieważ `n` określa rozmiar tablicy początkowej.

---

## `f_validateM`

```cpp
bool f_validateM(int m);
```

Funkcja sprawdza poprawność modułu.

Warunek:

```text
m > 0
```

---

## `f_validateValueInRange`

```cpp
bool f_validateValueInRange(int value, int min, int max);
```

Funkcja sprawdza, czy dana wartość znajduje się w określonym zakresie.

W programie używana jest między innymi do sprawdzania:

```text
0 <= seed < m
0 <= a < m
0 <= c < m
```

---

## `f_saveToFile`

```cpp
void f_saveToFile(const std::vector<int>& numbers, const std::string& filename);
```

Funkcja zapisuje wygenerowany ciąg liczb do pliku tekstowego.

Każda liczba zapisywana jest w osobnej linii, czyli w postaci jednej kolumny.

Przykład zawartości pliku:

```text
7
7
7
1
4
1
```

---

# Sposób implementacji

Program został zaimplementowany modularnie.

Oznacza to, że każda część programu odpowiada za osobny fragment działania:

```text
main.cpp       - obsługa menu i komunikacja z użytkownikiem
lcg.cpp        - implementacja liniowej metody kongruencyjnej
additive.cpp   - implementacja addytywnej metody kongruencyjnej
utils.cpp      - funkcje pomocnicze
```

Dzięki temu kod jest bardziej czytelny, łatwiejszy do testowania i prostszy do rozbudowy.

---

## Wykorzystanie wektora

Wygenerowane liczby są przechowywane w obiekcie:

```cpp
std::vector<int> numbers;
```

Każda nowa liczba jest dodawana do wektora za pomocą:

```cpp
numbers.push_back(value);
```

Dzięki temu funkcje generujące liczby nie zapisują ich bezpośrednio do pliku.

Najpierw zwracają gotowy wektor wyników, a dopiero później funkcja pomocnicza zapisuje ten wektor do pliku.

Takie rozwiązanie oddziela logikę generowania od logiki zapisu danych.

---

# Kompilacja

W katalogu z plikami należy uruchomić:

```bash
g++ main.cpp lcg.cpp additive.cpp utils.cpp -o program.exe
```

---

# Uruchomienie programu

W PowerShell program można uruchomić poleceniem:

```bash
.\program.exe
```

W terminalu Linux lub Git Bash:

```bash
./program.exe
```

---

# Przykład użycia

## Liniowa metoda kongruencyjna

Przykładowe dane wejściowe:

```text
Choose generation method:
1

How many numbers do you want to generate?:
6

Enter seed:
5

Enter max value:
12
```

Program oblicza współczynniki `m`, `a`, `c`, generuje liczby z przedziału:

```text
1 ... 12
```

i zapisuje wynik do pliku:

```text
lcg_numbers.txt
```

---

## Addytywna metoda kongruencyjna

Przykładowe dane wejściowe:

```text
Choose generation method:
2

Enter n:
6

Enter modulus m:
8

Enter seed for initial LCG table:
5
```

Program tworzy początkową tablicę za pomocą LCG, odwraca ją, wybiera parę `(2, 5)`, a następnie generuje liczby addytywną metodą kongruencyjną.

Wynik zostaje zapisany do pliku:

```text
additive_numbers.txt
```

---

# Pliki wynikowe

W zależności od wybranej metody program zapisuje dane do jednego z plików:

```text
lcg_numbers.txt
additive_numbers.txt
```

Każda liczba znajduje się w osobnej linii.

---

# Podsumowanie

Program realizuje dwa sposoby generowania liczb pseudolosowych:

1. **Liniowa metoda kongruencyjna**, w której każda kolejna wartość zależy od poprzedniej wartości oraz współczynników `a`, `c` i `m`.
2. **Addytywna metoda kongruencyjna**, w której kolejne wartości powstają na podstawie dwóch elementów zapisanych w tablicy.

Podział programu na osobne pliki pozwala zachować czytelność kodu oraz ułatwia dalszą rozbudowę projektu.
