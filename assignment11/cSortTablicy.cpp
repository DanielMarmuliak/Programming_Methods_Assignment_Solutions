#include "cSortTablicy.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <limits>


int cSortTablicy::readInt(const std::string& message) const{
    int value;
    std::cout << message;

    if(!(std::cin >> value)){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::runtime_error("Podano nieprawidlowa liczbe");
    }

    return value;
}


std::string cSortTablicy::methodName(int method) const {
    switch (method) {
        case 1:
            return "Shaker sort";
        case 2:
            return "Quick sort Lomuto";
        case 3:
            return "Quick sort Hoare";
        case 4:
            return "Heap sort";
        default:
            return "Nieznana metoda";
    }
}


std::string cSortTablicy::typeName(int type) const {
    switch (type) {
        case 1:
            return "losowa";
        case 2:
            return "posortowana rosnaco";
        case 3:
            return "posortowana malejaco";
        case 4:
            return "czesciowo uporzadkowana";
        default:
            return "nieznany typ";
    }
}


std::vector<int> cSortTablicy::generateArray(int n, int type) const{
    if(n <= 0)
        throw std::invalid_argument("Dlugosc tablicy musi byc dodatnia");
    
    std::vector<int> array(n);

    static std::mt19937 generator(std::random_device{}());

    switch(type){
        case 1:{
            // Fill the array with random numbers
            std::uniform_int_distribution<int> distribution(1, n * 10);
            for(int i = 0; i < n; i++){
                array[i] = distribution(generator);
            }
            break;
        }

        case 2:{
            // Create an ascending sorted array
            std::iota(array.begin(), array.end(), 1);
            break;
        }

        case 3:{
            // Create a descending sorted array
            for (int i = 0; i < n; i++) {
                array[i] = n - i;
            }

            break;
        }

        case 4: {
            // Create a partially sorted array with about 10% misplaced elements
            std::iota(array.begin(), array.end(), 1);

            if(n > 1){
                int wrongCount = n / 10;

                if(wrongCount < 2)
                    wrongCount = 2;

                std::vector<int> indexes(n);
                std::iota(indexes.begin(), indexes.end(), 0);
                std::shuffle(indexes.begin(), indexes.end(), generator);
                indexes.resize(wrongCount);

                int firstValue = array[indexes[0]];

                for(int i = 0; i < wrongCount - 1; i++){
                    array[indexes[i]] = array[indexes[i + 1]];
                }
                array[indexes[wrongCount - 1]] = firstValue;
            }
            break;
        }

        default:
            throw std::invalid_argument("Nieznany typ tablicy");
    }

    return array;
}


SortStats cSortTablicy::sortByMethod(cTablica& temp, int method) const{
    switch(method){
        case 1:
            return temp.shakerSort();
        case 2:
            return temp.quickSortLomuto();
        case 3:
            return temp.quickSortHoare();
        case 4:
            return temp.heapSort();
        default:
            throw std::invalid_argument("Nieznana metoda sortowania");
    }
}

void cSortTablicy::printStats(const SortStats& stats) const{
    std::cout << "Liczba porownan: " << stats.comparisons << "\n";
    std::cout << "Liczba przestawien: " << stats.swaps << "\n";
}

void cSortTablicy::inputFromKeyboard(){
    int n = readInt("Podaj liczbe elementow: ");

    if (n <= 0) 
        throw std::invalid_argument("Liczba elementow musi byc dodatnia");
    

    std::vector<int> values(n);

    for(int i = 0; i < n; i++){
        values[i] = readInt("Podaj element [" + std::to_string(i) + "]: ");
    }

    tablica.setData(values);

    std::cout << "Tablica zostala wczytana\n";
}


void cSortTablicy::generateFromKeyboard() {
    int n = readInt("Podaj dlugosc tablicy: ");

    std::cout << "\nRodzaje tablic:\n";
    std::cout << "1. Losowa\n";
    std::cout << "2. Posortowana rosnaco\n";
    std::cout << "3. Posortowana malejaco\n";
    std::cout << "4. Czesciowo uporzadkowana\n";

    int type = readInt("Wybierz rodzaj tablicy: ");

    tablica.setData(generateArray(n, type));

    std::cout << "Tablica zostala wygenerowana\n";
}


void cSortTablicy::sortCurrentArray() {
    if(tablica.size() == 0) 
        throw std::runtime_error("Najpierw wczytaj albo wygeneruj tablice");

    std::cout << "\nMetody sortowania:\n";
    std::cout << "1. Shaker sort\n";
    std::cout << "2. Quick sort Lomuto\n";
    std::cout << "3. Quick sort Hoare\n";
    std::cout << "4. Heap sort\n";

    int method = readInt("Wybierz metode sortowania: ");

    cTablica copy = tablica;

    std::cout << "\nTablica przed sortowaniem:\n";
    copy.print();

    SortStats stats = sortByMethod(copy, method);

    std::cout << "\nTablica po sortowaniu:\n";
    copy.print();

    std::cout << "\nMetoda: " << methodName(method) << "\n";
    printStats(stats);
}


void cSortTablicy::runBenchmark(const std::string& fileName){
    std::ofstream file(fileName);

    if(!file)
        throw std::runtime_error("Nie mozna utworzyc pliku wynikowego");
    

    std::vector<int> sizes = {100, 1000, 1000000};
    std::vector<int> types = {1, 2, 3, 4};
    std::vector<int> methods = {1, 2, 3, 4};

    char answer;

    std::cout << "\nUwaga: Shaker sort dla 1 000 000 elementow moze dzialac bardzo dlugo\n";
    std::cout << "Czy uruchomic Shaker sort dla 1 000 000 elementow? [t/n]: ";
    std::cin >> answer;

    bool runSlowSort = (answer == 't' || answer == 'T');

    file << "ZESTAWIENIE WYNIKOW SORTOWANIA\n\n";

    file << std::left
         << std::setw(25) << "Nazwa metody"
         << std::setw(18) << "Dlugosc tablicy"
         << std::setw(35) << "Rodzaj tablicy"
         << std::setw(20) << "Liczba porownan"
         << std::setw(20) << "Liczba przestawien"
         << "\n";

    file << std::string(118, '-') << "\n";

    for(int size : sizes){
        for(int type : types){
            std::vector<int> baseArray = generateArray(size, type);

            for(int method : methods){
                std::cout << "Test: "
                          << methodName(method)
                          << ", n = " << size
                          << ", typ = " << typeName(type)
                          << "\n";

                if(size == 1000000 && method == 1 && !runSlowSort){
                    file << std::left
                         << std::setw(25) << methodName(method)
                         << std::setw(18) << size
                         << std::setw(35) << typeName(type)
                         << std::setw(20) << "Pominieto"
                         << std::setw(20) << "Pominieto"
                         << "\n";

                    continue;
                }

                cTablica temp(baseArray);
                SortStats stats = sortByMethod(temp, method);

                file << std::left
                     << std::setw(25) << methodName(method)
                     << std::setw(18) << size
                     << std::setw(35) << typeName(type)
                     << std::setw(20) << stats.comparisons
                     << std::setw(20) << stats.swaps
                     << "\n";
            }
        }
    }

    file << "\n\nWNIOSKI:\n";
    file << "1. Shaker sort jest prosty, ale dla duzych tablic wykonuje bardzo duzo porownan i przestawien.\n";
    file << "2. Quick sort zwykle dziala bardzo szybko, szczegolnie dla danych losowych.\n";
    file << "3. Wariant Hoare'a zazwyczaj wykonuje mniej przestawien niz wariant Lomuto.\n";
    file << "4. Heap sort ma gwarantowana zlozonosc O(n log n), dlatego dobrze nadaje sie do duzych tablic.\n";
    file << "5. Tablice posortowane lub prawie posortowane sa latwiejsze dla prostych metod sortowania.\n";
    file << "6. Tablice posortowane malejaco sa trudne dla prostych metod opartych na zamianach sasiednich elementow.\n";

    file.close();

    std::cout << "\nWyniki zapisano do pliku: " << fileName << "\n";
}


void cSortTablicy::menu(){
    while(true){
        try{
            std::cout << "\n===== MENU =====\n";
            std::cout << "1. Wprowadz tablice z klawiatury\n";
            std::cout << "2. Wygeneruj tablice\n";
            std::cout << "3. Pokaz aktualna tablice\n";
            std::cout << "4. Posortuj aktualna tablice\n";
            std::cout << "5. Wykonaj testy i zapisz wyniki do pliku\n";
            std::cout << "0. Koniec programu\n";

            int choice = readInt("Wybierz opcje: ");

            switch(choice){
                case 1:
                    inputFromKeyboard();
                    break;

                case 2:
                    generateFromKeyboard();
                    break;

                case 3:
                    tablica.print();
                    break;

                case 4:
                    sortCurrentArray();
                    break;

                case 5:
                    runBenchmark("wyniki_sortowania.txt");
                    break;

                case 0:
                    std::cout << "Koniec programu\n";
                    return;

                default:
                    std::cout << "Nieznana opcja\n";
            }
        }catch(const std::exception& e) {
            std::cout << "Blad: " << e.what() << "\n";
        }
    }
}