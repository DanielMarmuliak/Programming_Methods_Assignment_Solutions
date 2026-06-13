#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <exception>

#include "Huffman.h"
#include "InputData.h"

// Runs one Huffman coding example
void runHuffmanExample(const std::vector<SymbolData>& symbols, const std::string& title) {
    std::cout << "\n==============================\n";
    std::cout << title << "\n";
    std::cout << "==============================\n";

    // Validate input data before building the tree
    validateInput(symbols);

    // Build Huffman tree
    Node* root = buildHuffmanTree(symbols);

    // Generate Huffman codes
    std::map<char, std::string> codes;
    generateCodes(root, "", codes);

    // Print results
    printCodes(symbols, codes);

    // Free memory
    deleteTree(root);
}

// Prints program menu
void printMenu() {
    std::cout << "\n========== MENU ==========\n";
    std::cout << "1. Data from example A\n";
    std::cout << "2. Data from example B\n";
    std::cout << "3. Error test: invalid frequency\n";
    std::cout << "4. Error test: duplicate symbol\n";
    std::cout << "5. Error test: too few symbols\n";
    std::cout << "6. Error test: empty input list\n";
    std::cout << "0. The end of program\n";
    std::cout << "Choose option: ";
}

int main() {
    int choice;
    do{
        printMenu();
        std::cin >> choice;

        try{
            switch(choice){
                case 1:
                    runHuffmanExample(getExampleDataA(), "Data from example A");
                    break;

                case 2:
                    runHuffmanExample(getExampleDataB(), "Data from example B");
                    break;

                case 3:
                    runHuffmanExample(getInvalidNegativeData(), "Test: negative frequency");
                    break;

                case 4:
                    runHuffmanExample(getInvalidDuplicateData(), "Test: duplicate symbol");
                    break;

                case 5:
                    runHuffmanExample(getInvalidTooFewSymbolsData(), "Test: only one symbol");
                    break;

                case 6: {
                    std::vector<SymbolData> emptyData;
                    runHuffmanExample(emptyData, "Test: emty input list");
                    break;
                }
                case 0:
                    std::cout << "The ehnd of program\n";
                    break;

                default:
                    std::cout << "Invalid menu option\n";
                    break;
            }
        }
        catch(const std::exception& e){
            std::cout << "Error: " << e.what() << "\n";
        }

    }while(choice != 0);

    return 0;
}