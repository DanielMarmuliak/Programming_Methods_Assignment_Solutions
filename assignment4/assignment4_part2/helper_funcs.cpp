#include "helper_funcs.h"

// Checks if character is a lowercase operand
bool f_isOperand(char c){
    if(c >= 'a' && c <= 'z'){
        return true;
    }
    return false;
}

// Checks if character is the unary operator '~'
bool f_isUnaryOperator(char c){
    if(c == '~') return true;
    return false;
}

// Checks if character is a binary operator
bool f_isBinaryOperator(char c){
    switch(c){
        case '=':
        case '<':
        case '>':
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
            return true;
        default:
            return false;
    }
}

// Checks if character is any valid operator
bool f_isOperator(char c){
    return f_isBinaryOperator(c) || f_isUnaryOperator(c);
}

// Checks if operator is right-associative
bool f_isRightAssociative(char c){
    if(c == '=' || c == '^' || c == '~')
        return true;
    return false;
}

// Returns operator priority
int f_priority(char c){
    switch(c){
        case '=':
            return 0;
        case '<':
        case '>':
            return 1;
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
        case '%':
            return 3;
        case '^':
            return 4;
        case '~':
            return 5;
        default:
            return -1;
    }
}

// Removes invalid characters from INF expression
std::string f_cleanINF(const std::string& s){
    std::string result;
    for(char c: s){
        if(f_isOperand(c))
            result += c;
        else if(f_isOperator(c))
            result += c;
        else if(c == '(' || c == ')')
            result += c;
    }
    return result;
}

// Removes invalid characters from ONP expression
std::string f_cleanONP(const std::string& s){
    std::string result;
    for(char c: s){
        if(f_isOperand(c))
            result += c;
        else if(f_isOperator(c))
            result += c;
    }
    return result;
}