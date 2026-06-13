# Program 02 – konwersja INF <-> ONP

## Opis programu
Program służy do konwersji wyrażeń zapisanych w dwóch notacjach:

- **INF** – notacja infiksowa
- **ONP** – odwrotna notacja polska

Program obsługuje dwa kierunki konwersji:
- `INF -> ONP`
- `ONP -> INF`

Jeżeli wyrażenie jest niepoprawne, program zwraca `error`
---

## Obsługiwane elementy

### Operandy
- małe litery od `a` do `z`

### Operatory
- `=`
- `<`
- `>`
- `+`
- `-`
- `*`
- `/`
- `%`
- `^`
- `~`

Operator `~` jest operatorem unarnym

### Nawiasy
- `(` `)` – tylko dla notacji INF

---

## Zasada działania programu

Program działa w kilku etapach:

1. odczytuje liczbę testów,
2. odczytuje kolejne linie wejściowe,
3. rozpoznaje, czy linia zaczyna się od `INF:` czy `ONP:`,
4. usuwa niepoprawne znaki z wyrażenia,
5. wykonuje odpowiednią konwersję,
6. wypisuje wynik

---

## Konwersja INF -> ONP
Do konwersji z INF do ONP program używa:
- stosu operatorów,
- priorytetów operatorów,
- łączności operatorów,
- kontroli poprawności składni

Operandy są dopisywane do wyniku, a operatory są odkładane na stos i zdejmowane zgodnie z priorytetami oraz nawiasami.

---

## Konwersja ONP -> INF
Do konwersji z ONP do INF program używa:
- stosu obiektów `Expr`

Każdy element stosu przechowuje:
- tekst wyrażenia,
- priorytet operatora głównego,
- operator główny,
- informację, czy jest to pojedynczy operand

Dzięki temu program potrafi poprawnie odbudować wyrażenie INF i dodać tylko potrzebne nawiasy

---

## Obsługa błędów
Program zwraca `error`, gdy:
- wyrażenie ma złą składnię,
- brakuje operandów lub operatorów,
- nawiasy są niepoprawne,
- końcowy zapis nie daje jednego poprawnego wyrażenia.

---

## Struktura plików

- `main.cpp` – główny program
- `helper_funcs.h`, `helper_funcs.cpp` – funkcje pomocnicze
- `expr.h` – struktura `Expr`
- `inf_to_onp.h`, `inf_to_onp.cpp` – konwersja INF -> ONP
- `onp_to_inf.h`, `onp_to_inf.cpp` – konwersja ONP -> INF

---

## Kompilacja

```bash
g++ main.cpp helper_funcs.cpp inf_to_onp.cpp onp_to_inf.cpp -o program.exe