#pragma once 

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>

struct Node{
    char symbol;
    double frequency;
    Node* left;
    Node* right;

    //Constructor for leaf node
    Node(char s, double f){
        symbol = s;
        frequency = f;
        left = nullptr;
        right = nullptr;
    };

    //Constructor for internal node
    Node(double f, Node* l, Node* r){
        symbol = '\0';
        frequency = f;
        left = l;
        right = r;
    };
    
    //Checks if the node is leaf
    bool isLeaf() const{
        return left == nullptr && right == nullptr;
    }
};

struct SymbolData{
    char symbol;
    double frequency;
};

struct CompareNodes{
    bool operator()(Node* first, Node* second){
        return first->frequency > second->frequency;
    }
};

//Builds Huffman tree and returns root node 
Node* buildHuffmanTree(const std::vector<SymbolData>& symbols);

//Generates Huffman codes for all symbols
void generateCodes(Node* root, const std::string& currentCode, 
                   std::map<char, std::string>& codes);

//Prints Huffman codes
void printCodes(const std::vector<SymbolData>& symbols, const std::map<char, std::string>& codes);

//Deletes Huffman tree from memory
void deleteTree(Node* root);