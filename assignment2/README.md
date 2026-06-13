# Laboratorium 2 – dopasowanie siatki identyfikacyjnej


W tym folderze znajduje się moje rozwiązanie zadania z laboratorium 2. Starałem się napisać program możliwie prosto i czytelnie, dlatego kod został podzielony na kilka plików, a funkcje mają jasne nazwy i komentarze.

## Co znajduje się w folderze

- `main.cpp` – uruchamia program
- `f_app.*` – główna logika programu
- `f_io.*` – odczyt danych z plików i zapis wyniku
- `f_match.*` – obliczanie błędu dopasowania i wybór najlepszej siatki
- `f_types.h` – pomocnicze struktury danych
- `plot_best_fit.py` – skrypt w Pythonie do wykonania wykresów
- `plot_SEAK.png`, `plot_SEB.png` – gotowe wykresy
- `wynik_SEAK.txt`, `wynik_SEB.txt` – przykładowe wyniki dla dostarczonych danych

## Założenie programu

Program porównuje siatkę nieznanego modelu z 81 siatkami identyfikacyjnymi i wybiera tę, dla której błąd dopasowania jest najmniejszy.

Do obliczeń użyłem wzoru z treści zadania:

```text
mse = sqrt( sum((y_i - Y_i)^2) + sum((x_i - X_i)^2) )
```

Porównanie jest wykonywane tylko dla współrzędnych punktów, czyli od 7. elementu wiersza.
Pierwsze 6 wartości traktowane są jako parametry modelu i nie biorą udziału w liczeniu błędu.

## Kompilacja programu

### Wariant z `g++`

```bash
g++ -std=c++17 main.cpp f_app.cpp f_io.cpp f_match.cpp -o lab2_best_match
```

Tutaj warto zaznaczyć, że `lab2_best_match` po `-o` jest tylko nazwą pliku wykonywalnego. Nie musi to być nazwa folderu.

### Wariant z `CMake`

```bash
cmake -S . -B build
cmake --build build
```

## Uruchomienie programu

Po uruchomieniu program prosi kolejno o podanie:

1. nazwy modelu,
2. nazwy pliku z siatkami identyfikacyjnymi,
3. nazwy pliku z nieznaną siatką,
4. nazwy pliku wyjściowego.

Przykład uruchomienia dla silnika asynchronicznego klatkowego:

```text
Model name: Silnik elektryczny asynchroniczny klatkowy
Grid file name: siatka_SEAK.txt
Unknown model file name: nmSEAK.txt
Output file name: wynik_SEAK.txt
```

## Ważna uwaga dotycząca ścieżek do plików

Podczas testowania programu pojawił się u mnie problem z komunikatem:

```text
Error: Cannot open file: siatka_SEAK.txt
```

Powód był prosty: program był uruchamiany z folderu głównego, a pliki `.txt` znajdowały się w podfolderze `Wykresy`.

W takiej sytuacji nie wystarczy wpisać samej nazwy pliku. Trzeba podać ścieżkę względną, na przykład:

```text
Model name: Silnik elektryczny asynchroniczny klatkowy
Grid file name: Wykresy\siatka_SEAK.txt
Unknown model file name: Wykresy\nmSEAK.txt
Output file name: wynik_SEAK.txt
```

Jeśli plik wynikowy również ma zostać zapisany w tym samym podfolderze, wtedy można wpisać:

```text
Output file name: Wykresy\wynik_SEAK.txt
```

Analogicznie dla silnika bezszczotkowego:

```text
Model name: Silnik elektryczny bezszczotkowy
Grid file name: Wykresy\siatkaSEB.txt
Unknown model file name: Wykresy\nmSEB.txt
Output file name: wynik_SEB.txt
```

Jeżeli wszystkie pliki `.txt` znajdują się w tym samym folderze co program, wtedy można wpisywać same nazwy plików bez ścieżki.

## Wyniki dla dostarczonych danych

Dla plików dołączonych do zadania program wyznaczył:

- dla `SEAK` – najlepsze dopasowanie: **siatka nr 52**, minimalne MSE = **0.131767298**,
- dla `SEB` – najlepsze dopasowanie: **siatka nr 9**, minimalne MSE = **1.181461003**.

## Wykresy w Pythonie

Do zadania przygotowałem też osobny skrypt w Pythonie, który rysuje wykres punktowy siatki nieznanej oraz najlepiej dopasowanej siatki modelowej.

Uruchomienie:

```bash
python plot_best_fit.py
```

Najwygodniej jest trzymać plik `plot_best_fit.py` oraz pliki `.txt` w tym samym folderze. Wtedy nie trzeba zmieniać ścieżek w kodzie.
Jeśli pliki znajdują się w innym miejscu, trzeba odpowiednio poprawić ścieżki.

## Dodatkowa uwaga

Kod został rozdzielony na kilka plików celowo, żeby łatwiej było pokazać, za co odpowiada każda część programu:
- osobno odczyt i zapis plików,
- osobno obliczenia,
- osobno uruchamianie programu.

Dodałem też komentarze nad funkcjami, żeby podczas sprawdzania kodu było od razu widać, co wykonuje każda z nich.
