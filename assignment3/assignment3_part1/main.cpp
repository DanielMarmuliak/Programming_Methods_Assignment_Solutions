#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include "algorithms.h"

using namespace std;

// Wypisuje dla kolejnych zapytań pary w postaci:
// (liczba_wystąpień indeks)
static void f_printQueryResults(const vector<int64_t>& tab, const vector<int64_t>& queries) {
    for (size_t i = 0; i < queries.size(); ++i) {
        int count = f_countOccurrences(tab, queries[i]);
        int index = f_interpolationSearch(tab, queries[i]);

        cout << '(' << count << ' ' << index << ')';

        if (i + 1 < queries.size()) {
            cout << ' ';
        }
    }
    cout << '\n';
}

// Wypisuje maksymalnie 200 pierwszych elementów po usunięciu duplikatów.
// Co 50 elementów przechodzi do nowej linii.
static void f_printWithoutDuplicates(const vector<int64_t>& tab, int newSize) {
    int limit = min(newSize, 200);

    for (int i = 0; i < limit; ++i) {
        cout << tab[i];

        bool endOfLine = ((i + 1) % 50 == 0);
        bool lastElement = (i + 1 == limit);

        if (lastElement || endOfLine) {
            cout << '\n';
        } else {
            cout << ' ';
        }
    }

    // Gdy po usunięciu duplikatów tablica jest pusta,
    // zachowujemy poprawny format wyjścia.
    if (limit == 0) {
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testSets = 0;
    cin >> testSets;

    for (int setNumber = 0; setNumber < testSets; ++setNumber) {
        int n = 0;
        cin >> n;

        vector<int64_t> tab(n);
        for (int i = 0; i < n; ++i) {
            cin >> tab[i];
        }

        int q = 0;
        cin >> q;

        vector<int64_t> queries(q);
        for (int i = 0; i < q; ++i) {
            cin >> queries[i];
        }

        f_printQueryResults(tab, queries);

        // Po zakończeniu obsługi zapytań można nadpisać tablicę,
        // usuwając duplikaty bez użycia dodatkowej pamięci.
        int newSize = f_removeDuplicates(tab);
        f_printWithoutDuplicates(tab, newSize);
    }

    return 0;
}