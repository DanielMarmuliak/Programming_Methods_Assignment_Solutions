#include "f_app.h"

#include <exception>
#include <iostream>

// Główna funkcja programu.
// Uruchamia całą logikę aplikacji przez funkcję f_run().
// Dodatkowo przechwytuje błędy i wypisuje komunikat,
// jeśli wystąpi problem np. z otwarciem pliku lub formatem danych.
int main()
{
    try
    {
        f_run();
    }
    catch (const std::exception& error)
    {
        std::cerr << "Error: " << error.what() << '\n';
        return 1;
    }

    return 0;
}
