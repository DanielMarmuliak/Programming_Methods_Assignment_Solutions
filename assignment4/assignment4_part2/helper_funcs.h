#ifndef HELPER_FUNCS_H
#define HELPER_FUNCS_H

#include <string>

// Checks if character is a lowercase operand.
bool f_isOperand(char c);

// Checks if character is the unary operator '~'
bool f_isUnaryOperator(char c);

// Checks if character is a binary operator
bool f_isBinaryOperator(char c);

// Checks if character is any valid operator
bool f_isOperator(char c);

// Checks if operator is right-associative
bool f_isRightAssociative(char c);

// Returns operator priority
int f_priority(char c);

// Removes invalid characters from INF expression
std::string f_cleanINF(const std::string& s);

// Removes invalid characters from ONP expression
std::string f_cleanONP(const std::string& s);




#endif