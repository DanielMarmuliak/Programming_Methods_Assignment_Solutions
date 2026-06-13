#include "algorithms.h"

using namespace std;

// Zwraca indeks pierwszego elementu >= value.
// Jeżeli taki element nie istnieje, zwracany jest rozmiar tablicy.
int f_findFirstNotLess(const vector<int64_t>& tab, int64_t value) {
    int left = 0;
    int right = static_cast<int>(tab.size());

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (tab[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

// Zwraca indeks pierwszego elementu > value.
// Jeżeli taki element nie istnieje, zwracany jest rozmiar tablicy.
int f_findFirstGreater(const vector<int64_t>& tab, int64_t value) {
    int left = 0;
    int right = static_cast<int>(tab.size());

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (tab[mid] <= value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

// Liczy liczbę wystąpień wartości value w tablicy uporządkowanej niemalejąco.
// Złożoność: O(log n).
int f_countOccurrences(const vector<int64_t>& tab, int64_t value) {
    int first = f_findFirstNotLess(tab, value);

    if (first == static_cast<int>(tab.size()) || tab[first] != value) {
        return 0;
    }

    int last = f_findFirstGreater(tab, value);
    return last - first;
}

// Realizuje wyszukiwanie interpolacyjne.
// Zwraca indeks znalezionego elementu lub -1, gdy wartości nie ma w tablicy.
//
// Uwaga:
// Przy wielokrotnych wystąpieniach tej samej wartości funkcja może zwrócić
// dowolny poprawny indeks jednego z tych wystąpień.
int f_interpolationSearch(const vector<int64_t>& tab, int64_t value) {
    if (tab.empty()) {
        return -1;
    }

    int left = 0;
    int right = static_cast<int>(tab.size()) - 1;

    while (left <= right && value >= tab[left] && value <= tab[right]) {
        // Jeżeli wszystkie elementy w analizowanym przedziale są równe,
        // to dalsze wyznaczanie pozycji interpolacyjnej nie ma sensu.
        if (tab[left] == tab[right]) {
            return (tab[left] == value) ? left : -1;
        }

        // Użycie typu __int128 chroni przed przepełnieniem
        // przy obliczaniu pozycji interpolacyjnej.
        __int128 numerator =
            static_cast<__int128>(value - tab[left]) * (right - left);
        __int128 denominator =
            static_cast<__int128>(tab[right] - tab[left]);

        int pos = left + static_cast<int>(numerator / denominator);

        if (tab[pos] == value) {
            return pos;
        }

        if (tab[pos] < value) {
            left = pos + 1;
        } else {
            right = pos - 1;
        }
    }

    return -1;
}

// Usuwa duplikaty "w miejscu", bez użycia dodatkowej tablicy.
// Zwraca nowy logiczny rozmiar tablicy po usunięciu powtórzeń.
// Złożoność: O(n).
int f_removeDuplicates(vector<int64_t>& tab) {
    if (tab.empty()) {
        return 0;
    }

    int writeIndex = 1;

    for (int readIndex = 1; readIndex < static_cast<int>(tab.size()); ++readIndex) {
        if (tab[readIndex] != tab[writeIndex - 1]) {
            tab[writeIndex] = tab[readIndex];
            ++writeIndex;
        }
    }

    return writeIndex;
}