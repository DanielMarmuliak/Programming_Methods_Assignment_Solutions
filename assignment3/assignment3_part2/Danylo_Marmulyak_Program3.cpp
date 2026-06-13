#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/*
    Funkcja wypisuje jeden podzial liczby do pliku.
    Elementy podzialu sa rozdzielone spacjami.
*/
void f_writePartition(ofstream& file, const vector<int>& partition) {
    for (int i = 0; i < (int)partition.size(); i++) {
        file << partition[i];
        if (i + 1 < (int)partition.size()) {
            file << ' ';
        }
    }
    file << '\n';
}

/*
    Funkcja rekurencyjnie generuje wszystkie podzialy liczby.

    @params
    - remaining oznacza, jaka czesc liczby n zostala jeszcze do podzielenia,
    - maxValue oznacza najwieksza wartosc, jaka mozna teraz dopisac,
      aby zachowac porzadek nierosnacy.

    Dzieki temu kazdy podzial:
    - sklada sie z liczb dodatnich,
    - jest zapisany w kolejnosci nierosnacej,
    - pojawia sie tylko raz.
*/
void f_generatePartitionsRec(ofstream& file, vector<int>& partition, int remaining, int maxValue) {
    if (remaining == 0) {
        f_writePartition(file, partition);
        return;
    }

    int start = min(remaining, maxValue);

    for (int value = start; value >= 1; value--) {
        partition.push_back(value);
        f_generatePartitionsRec(file, partition, remaining - value, value);
        partition.pop_back();
    }
}

/*
    Funkcja otwiera plik i uruchamia generowanie wszystkich podzialow liczby n.
*/
void f_generatePartitions(int n, const string& filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Blad przy otwieraniu pliku." << endl;
        return;
    }

    vector<int> partition;
    f_generatePartitionsRec(file, partition, n, n);

    file.close();
}

int main() {
    int n;
    string filename;

    cout << "Podaj liczbe n: ";
    cin >> n;

    cout << "Podaj nazwe pliku wyjsciowego: ";
    cin >> filename;

    if (n <= 0) {
        cerr << "Blad: n musi byc dodatnie." << endl;
        return 1;
    }

    f_generatePartitions(n, filename);

    cout << "Plik zostal wygenerowany poprawnie." << endl;

    return 0;
}