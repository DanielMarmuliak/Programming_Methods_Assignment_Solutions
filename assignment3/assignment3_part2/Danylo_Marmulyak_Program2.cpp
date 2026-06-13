#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/*
    Funkcja wypisuje aktualny k-elementowy podzbiór do pliku.
    Elementy są rozdzielone spacją.
*/
void f_writeSubset(ofstream& file, const vector<int>& A) {
    for (int i = 0; i < (int)A.size(); i++) {
        file << A[i];
        if (i + 1 < (int)A.size()) {
            file << ' ';
        }
    }
    file << '\n';
}

/*
    Funkcja generuje wszystkie k-elementowe podzbiory zbioru {1, ..., n}
    w porządku leksykograficznym i zapisuje je do pliku.
*/
void f_generateKSubsets(int n, int k, const string& filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Blad przy otwieraniu pliku." << endl;
        return;
    }

    // Tworzymy pierwszy podzbiór: 1, 2, ..., k
    vector<int> A(k);
    for (int i = 0; i < k; i++) {
        A[i] = i + 1;
    }

    // p odpowiada pozycji zmienianego elementu zgodnie z pseudokodem
    int p = k - 1;

    while (p >= 0) {
        f_writeSubset(file, A);

        // Jezeli ostatni element osiagnal n,
        // cofamy sie do poprzedniej pozycji.
        if (A[k - 1] == n) {
            p = p - 1;
        } else {
            p = k - 1;
        }

        // Jezeli nadal istnieje pozycja do zmiany,
        // budujemy kolejny podzbiór.
        if (p >= 0) {
            for (int i = k - 1; i >= p; i--) {
                A[i] = A[p] + (i - p) + 1;
            }
        }
    }

    file.close();
}

int main() {
    int n, k;
    string filename;

    cout << "Podaj liczbe elementow zbioru n: ";
    cin >> n;

    cout << "Podaj liczbe elementow w podzbiorze k: ";
    cin >> k;

    cout << "Podaj nazwe pliku wyjsciowego: ";
    cin >> filename;

    if (n <= 0) {
        cerr << "Blad: n musi byc dodatnie." << endl;
        return 1;
    }

    if (k <= 0) {
        cerr << "Blad: k musi byc dodatnie." << endl;
        return 1;
    }

    if (k >= n) {
        cerr << "Blad: musi zachodzic warunek k < n." << endl;
        return 1;
    }

    f_generateKSubsets(n, k, filename);

    cout << "Plik zostal wygenerowany poprawnie." << endl;

    return 0;
}