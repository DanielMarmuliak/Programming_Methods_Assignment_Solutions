# Laboratorium 10 — Algorytm Huffmana

## Temat zadania

Celem zadania jest zaimplementowanie algorytmu Huffmana, który służy do budowania optymalnego kodu prefiksowego dla podanych symboli i ich częstości występowania.

W programie zastosowano:

* podział programu na pliki nagłówkowe i implementacyjne,
* tematyczne pogrupowanie funkcji,
* kolejkę priorytetową,
* drzewo binarne Huffmana,
* rekurencyjne generowanie kodów,
* własne klasy wyjątków dziedziczące po `std::runtime_error`,
* obsługę błędów za pomocą `try-catch`.

---

## Struktura projektu

Projekt składa się z następujących plików:

```text
main.cpp
Huffman.h
Huffman.cpp
InputData.h
InputData.cpp
Exceptions.h
README.md
```

### Opis plików

#### `main.cpp`

Główny plik programu.
Zawiera funkcję `main()`, menu programu oraz funkcję pomocniczą `runHuffmanExample()`, która uruchamia cały proces kodowania Huffmana dla wybranego zestawu danych.

#### `Huffman.h`

Plik nagłówkowy zawierający deklaracje struktur i funkcji związanych z algorytmem Huffmana.

Znajdują się tutaj między innymi:

* struktura `Node`,
* struktura `SymbolData`,
* struktura `CompareNodes`,
* deklaracje funkcji do budowania drzewa, generowania kodów, wypisywania wyników i usuwania drzewa.

#### `Huffman.cpp`

Plik implementacyjny zawierający właściwą logikę algorytmu Huffmana.

Zaimplementowano tutaj funkcje:

* `buildHuffmanTree()`,
* `generateCodes()`,
* `printCodes()`,
* `deleteTree()`.

#### `InputData.h`

Plik nagłówkowy z deklaracjami funkcji odpowiedzialnych za dane wejściowe oraz ich walidację.

#### `InputData.cpp`

Plik implementacyjny zawierający przykładowe zestawy danych oraz funkcję `validateInput()`.

Funkcja ta sprawdza, czy dane są poprawne przed rozpoczęciem budowy drzewa Huffmana.

#### `Exceptions.h`

Plik zawierający własne klasy wyjątków, które dziedziczą po `std::runtime_error`.

---

## Opis algorytmu Huffmana

Algorytm Huffmana służy do tworzenia optymalnego kodu prefiksowego.

Oznacza to, że:

* symbole występujące częściej otrzymują krótsze kody,
* symbole występujące rzadziej otrzymują dłuższe kody,
* żaden kod nie jest początkiem innego kodu.

Dzięki temu zakodowany tekst może zajmować mniej miejsca.

---

## Sposób działania programu

Program działa według następującego schematu:

1. Użytkownik wybiera zestaw danych z menu.
2. Program sprawdza poprawność danych wejściowych.
3. Dla każdego symbolu tworzony jest osobny liść drzewa.
4. Wszystkie liście są dodawane do kolejki priorytetowej.
5. Program pobiera z kolejki dwa węzły o najmniejszej częstości.
6. Z tych dwóch węzłów tworzony jest nowy węzeł nadrzędny.
7. Nowy węzeł jest dodawany z powrotem do kolejki.
8. Kroki 5–7 powtarzają się, dopóki w kolejce nie zostanie jeden element.
9. Ostatni element kolejki jest korzeniem drzewa Huffmana.
10. Program przechodzi rekurencyjnie po drzewie i generuje kody.
11. Wyniki są wypisywane na ekranie.
12. Drzewo jest usuwane z pamięci.

---

## Kolejka priorytetowa

W programie wykorzystano kolejkę priorytetową:

```cpp
std::priority_queue<Node*, std::vector<Node*>, CompareNodes> pq;
```

Domyślnie `priority_queue` w C++ ustawia największy element na początku.

W algorytmie Huffmana potrzebujemy odwrotnie — na początku muszą znajdować się elementy o najmniejszej częstości.

Dlatego zastosowano własny komparator:

```cpp
struct CompareNodes {
    bool operator()(Node* first, Node* second) const {
        return first->frequency > second->frequency;
    }
};
```

Dzięki temu kolejka priorytetowa działa tak, że na jej początku znajduje się węzeł z najmniejszą wartością `frequency`.

---

## Generowanie kodów Huffmana

Do wygenerowania kodów używana jest funkcja rekurencyjna:

```cpp
void generateCodes(Node* root, const std::string& currentCode,
                   std::map<char, std::string>& codes);
```

Funkcja przechodzi po gotowym drzewie Huffmana.

Przyjęto zasadę:

```text
przejście w lewo  -> 0
przejście w prawo -> 1
```

Jeżeli funkcja trafi do liścia, zapisuje gotowy kod dla symbolu znajdującego się w tym liściu.

Przykład:

```text
root -> lewo        = 0
root -> prawo lewo  = 10
root -> prawo prawo = 11
```

---

## Obsługa wyjątków

W projekcie zaimplementowano własne klasy wyjątków dziedziczące po `std::runtime_error`.

Plik `Exceptions.h` zawiera między innymi:

```cpp
class EmptyInputException : public std::runtime_error
```

```cpp
class TooFewSymbolsException : public std::runtime_error
```

```cpp
class InvalidFrequencyException : public std::runtime_error
```

```cpp
class DuplicateSymbolException : public std::runtime_error
```

Wyjątki są rzucane w funkcji `validateInput()`.

Przykładowo:

```cpp
if (symbols.empty()) {
    throw EmptyInputException();
}
```

W funkcji `main()` wyjątki są przechwytywane za pomocą bloku:

```cpp
try {
    // kod programu
}
catch (const std::exception& e) {
    std::cout << "BLAD: " << e.what() << "\n";
}
```

Ponieważ własne wyjątki dziedziczą po `std::runtime_error`, a `std::runtime_error` dziedziczy po `std::exception`, można je wszystkie obsłużyć jednym blokiem `catch`.

---

## Przykładowe dane poprawne

### Dane z zadania A

```text
A 12
B 7
I 18
M 10
S 9
X 5
Z 2
```

### Dane z zadania B

```text
c 0.11
e 0.22
i 0.16
r 0.12
s 0.15
t 0.10
x 0.14

```

---

## Przykładowe dane błędne

Program pokazuje działanie wyjątków dla różnych rodzajów błędnych danych.

### Ujemna częstość

```text
A 12
B -7
C 5
```

Wynik:

```text
Error: The frequency or probability must be greater than zero
```

### Powtórzony symbol

```text
A 12
B 7
A 5
```

Wynik:

```text
Error: The same symbol cannot appear more than once
```

### Tylko jeden symbol

```text
A 12
```

Wynik:

```text
Eror: To build a Huffman tree, at least two symbols are needed
```

### Pusta lista danych

Wynik:

```text
Error: The input list is empty
```

---

## Kompilacja programu

Program można skompilować za pomocą komendy:

```bash
g++ main.cpp Huffman.cpp InputData.cpp -o program
```

---

## Uruchomienie programu

Na systemie Linux / macOS:

```bash
./program
```

Na systemie Windows:

```bash
program.exe
```

---

## Wnioski

W zadaniu wykorzystano drzewo binarne oraz kolejkę priorytetową do implementacji algorytmu Huffmana. Dzięki zastosowaniu własnego komparatora kolejka priorytetowa zwraca elementy o najmniejszej częstości jako pierwsze. Rekurencyjne przejście po drzewie pozwala wygenerować kody binarne dla wszystkich symboli.

Zastosowanie własnych klas wyjątków pozwoliło uporządkować obsługę błędów i zaprezentować reakcję programu na różne niepoprawne dane wejściowe.
