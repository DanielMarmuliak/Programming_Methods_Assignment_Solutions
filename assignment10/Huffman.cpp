#include "Huffman.h"

#include <iostream>
#include <iomanip>



Node* buildHuffmanTree(const std::vector<SymbolData>& symbols){
    std::priority_queue<Node*, std::vector<Node*>, CompareNodes> pq;

    //Create laef nodes and add them to pq
    for(const SymbolData& item: symbols){
        Node* newNode = new Node(item.symbol, item.frequency);
        pq.push(newNode);
    }

    // BUild tree by combining two nodes with the smallest frequency
    while(pq.size() > 1){
        Node* first = pq.top();
        pq.pop();

        Node* second = pq.top();
        pq.pop();

        double sum = first->frequency + second->frequency;
        Node* parent = new Node(sum, first, second);
        pq.push(parent);        
    }
    return pq.top();
}

void generateCodes(Node* root, const std::string& currentCode, std::map<char, std::string>& codes){
    if(root == nullptr) return;

    if(root->isLeaf()){
        codes[root->symbol] = currentCode;
        return;
    }

    generateCodes(root->left, currentCode + "0", codes);
    generateCodes(root->right, currentCode + "1", codes);
}


void printCodes(const std::vector<SymbolData>& symbols, const std::map<char, std::string>& codes){
    std::cout << "\nEncoding:\n";
    std::cout << "--------------------------------\n";
    std::cout << std::left << std::setw(10) << "Symbol"
              << std::setw(15) << "Frequency"
              << std::setw(15) << "Code" << "\n";
    std::cout << "--------------------------------\n";

    for (const SymbolData& item : symbols) {
        std::cout << std::left << std::setw(10) << item.symbol
                  << std::setw(15) << item.frequency
                  << std::setw(15) << codes.at(item.symbol) << "\n";
    }
    std::cout << "--------------------------------\n";
}

void deleteTree(Node* root){
    if(root == nullptr) return;

    deleteTree(root->left);
    deleteTree(root->right);
    
    delete root;
}

                   