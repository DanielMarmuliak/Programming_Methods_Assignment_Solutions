#ifndef EXPR_H
#define EXPR_H

#include <string>
// Stores one expression used in ONP -> INF conversion.
struct Expr{
    std::string text;
    int priority;
    char rootOp;
    bool isOperand;

    Expr()
    : text(""), priority(-1), rootOp('\0'), isOperand(false) {}
    
    Expr(const std::string t, int p, char r, bool operand)
    : text(t), priority(p), rootOp(r), isOperand(operand) {}
};




#endif