#ifndef F_IO_H
#define F_IO_H

#include "f_types.h"
#include <string>
#include <vector>

// Zamienia jeden wiersz tekstu na wektor liczb typu double.
std::vector<double> f_parse_line(const std::string& line);

// Odczytuje wszystkie siatki z pliku tekstowego.
std::vector<Grid> f_read_grids_from_file(const std::string& file_name);

// Zapisuje końcowy wynik programu do pliku tekstowego.
void f_write_result_file(
    const std::string& file_name,
    const std::string& model_name,
    const MatchResult& result);

// Łączy liczby z wektora w jeden tekst rozdzielony spacjami.
std::string f_join_numbers(const std::vector<double>& values);

#endif
