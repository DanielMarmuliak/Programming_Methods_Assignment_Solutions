from pathlib import Path
import math
import matplotlib.pyplot as plt

# Zamienia jeden wiersz tekstu na listę liczb typu float.
# Funkcja dzieli tekst po spacjach i konwertuje każdą wartość na liczbę.
def f_parse_line(line: str) -> list[float]:
    return [float(value) for value in line.split()]

# Odczytuje siatki z pliku tekstowego.
# Każda siatka jest zapisana w dwóch kolejnych wierszach:
# - pierwszy wiersz to współrzędne Y,
# - drugi wiersz to współrzędne X.
# Funkcja zwraca listę słowników w postaci:
# {"y": [...], "x": [...]}
def f_read_grids(file_name: str) -> list[dict]:
    rows = []
    with open(file_name, "r", encoding="utf-8") as file:
        for line in file:
            line = line.strip()
            if line:
                rows.append(f_parse_line(line))

    if len(rows) % 2 != 0:
        raise ValueError(f"Plik powinien zawierać parzystą liczbę niepustych wierszy: {file_name}")

    grids = []
    for i in range(0, len(rows), 2):
        grids.append({"y": rows[i], "x": rows[i + 1]})
    return grids

# Oblicza błąd dopasowania pomiędzy siatką nieznaną
# a jedną siatką wzorcową.
# Pierwsze 6 wartości są pomijane, ponieważ są to parametry modelu,
# a nie współrzędne punktów.
# Funkcja zwraca pierwiastek z sumy kwadratów różnic
# dla współrzędnych Y oraz X.
def f_compute_mse(unknown_grid: dict, candidate_grid: dict) -> float:
    start = 6
    total = 0.0

    for unknown_y, candidate_y in zip(unknown_grid["y"][start:], candidate_grid["y"][start:]):
        total += (unknown_y - candidate_y) ** 2

    for unknown_x, candidate_x in zip(unknown_grid["x"][start:], candidate_grid["x"][start:]):
        total += (unknown_x - candidate_x) ** 2

    return math.sqrt(total)

# Szuka najlepiej dopasowanej siatki spośród wszystkich siatek wzorcowych.
# Dla każdej siatki oblicza błąd dopasowania i wybiera tę,
# dla której wartość błędu jest najmniejsza.
# Zwraca:
# - indeks najlepszej siatki,
# - minimalną wartość błędu,
# - dane najlepszej siatki.
def f_find_best_match(unknown_grid: dict, candidate_grids: list[dict]) -> tuple[int, float, dict]:
    best_index = -1
    best_mse = None
    best_grid = None

    for index, candidate_grid in enumerate(candidate_grids):
        mse = f_compute_mse(unknown_grid, candidate_grid)
        if best_mse is None or mse < best_mse:
            best_index = index
            best_mse = mse
            best_grid = candidate_grid

    return best_index, best_mse, best_grid

# Tworzy wykres porównujący siatkę nieznaną
# z najlepiej dopasowaną siatką wzorcową.
# Funkcja:
# 1. odczytuje dane z plików,
# 2. wyszukuje najlepsze dopasowanie,
# 3. pobiera współrzędne punktów,
# 4. rysuje oba zestawy punktów na jednym wykresie,
# 5. zapisuje wykres do pliku PNG.
def f_make_plot(grid_file: str, unknown_file: str, title: str, output_png: str) -> None:
    candidate_grids = f_read_grids(grid_file)
    unknown_grid = f_read_grids(unknown_file)[0]

    best_index, best_mse, best_grid = f_find_best_match(unknown_grid, candidate_grids)

    unknown_x = unknown_grid["x"][6:]
    unknown_y = unknown_grid["y"][6:]
    best_x = best_grid["x"][6:]
    best_y = best_grid["y"][6:]

    plt.figure(figsize=(8, 5))
    plt.scatter(unknown_x, unknown_y, s=18, label="siatka nieznana")
    plt.scatter(best_x, best_y, s=18, marker="x", label=f"najlepsza siatka nr {best_index + 1}")
    plt.title(f"{title}\nminimalne MSE = {best_mse:.9f}")
    plt.xlabel("X")
    plt.ylabel("Y")
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.savefig(output_png, dpi=200)
    plt.show()
    plt.close()

# Główna funkcja skryptu Python.
# Uruchamia tworzenie dwóch wykresów:
# - dla modelu SEAK,
# - dla modelu SEB.
# Każdy wykres jest zapisywany do osobnego pliku PNG.
def f_main() -> None:
    base_path = Path(__file__).resolve().parent

    f_make_plot(
        str(base_path / "siatka_SEAK.txt"),
        str(base_path / "nmSEAK.txt"),
        "Silnik elektryczny asynchroniczny klatkowy",
        str(base_path / "plot_SEAK.png"),
    )

    f_make_plot(
        str(base_path / "siatkaSEB.txt"),
        str(base_path / "nmSEB.txt"),
        "Silnik elektryczny bezszczotkowy",
        str(base_path / "plot_SEB.png"),
    )


if __name__ == "__main__":
    f_main()