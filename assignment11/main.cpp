#include "cSortTablicy.h"

#include <iostream>

int main(){
    try{
        cSortTablicy program;
        program.menu();
    }catch(const std::exception& e){
        std::cout << "Blad krytyczny: " << e.what() << "\n";
    }

    return 0;
}