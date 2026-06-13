#include <iostream>
#include "helper_funcs.h"
#include "inf_to_onp.h"
#include "onp_to_inf.h"
#include <limits>



// Main program:
// 1. reads number of lines,
// 2. reads each line,
// 3. detects INF or ONP,
// 4. cleans expression,
// 5. converts expression,
// 6. prints result
int main() {
    int n;
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < n; i++) {
        std::string line;
        std::getline(std::cin, line);

        if (line.rfind("INF:", 0) == 0) {
            std::string expr = line.substr(4);
            std::string cleaned = f_cleanINF(expr);
            std::string result = f_infToOnp(cleaned);
            std::cout << "ONP: " << result << "\n";
        }
        else if (line.rfind("ONP:", 0) == 0) {
            std::string expr = line.substr(4);
            std::string cleaned = f_cleanONP(expr);
            std::string result = f_onpToInf(cleaned);
            std::cout << "INF: " << result << "\n";
        }
    }

    return 0;
}