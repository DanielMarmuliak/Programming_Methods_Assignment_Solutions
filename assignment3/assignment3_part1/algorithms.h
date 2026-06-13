#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <cstdint>
#include <vector>

int f_findFirstNotLess(const std::vector<std::int64_t>& tab, std::int64_t value);
int f_findFirstGreater(const std::vector<std::int64_t>& tab, std::int64_t value);
int f_countOccurrences(const std::vector<std::int64_t>& tab, std::int64_t value);
int f_interpolationSearch(const std::vector<std::int64_t>& tab, std::int64_t value);
int f_removeDuplicates(std::vector<std::int64_t>& tab);

#endif