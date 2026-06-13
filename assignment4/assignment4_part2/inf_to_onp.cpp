#include "inf_to_onp.h"
#include "helper_funcs.h"
#include "expr.h"
#include <string>
#include <stack>
#include <iostream>

// Stores current parser state for INF expression
enum Expect{
    EXPECT_OPERAND,
    EXPECT_OPERATOR
};

// Decides if the top operator should be popped from stack
bool f_shouldPop(char topOp, char curOp){
    if(topOp == '(')
        return false;
    
    if(f_isRightAssociative(curOp))
        return f_priority(topOp) > f_priority(curOp);
    else
        return f_priority(topOp) >= f_priority(curOp);    
}

// Converts cleaned INF expression to ONP
// Returns "error" if expression is invalid
std::string f_infToOnp(const std::string& expr){
    std::string out_s;
    std::stack<char> opStack;
    Expect state = EXPECT_OPERAND;

    for(char token: expr){
        // Expecting an operand, '(' or '~'
        if(state == EXPECT_OPERAND){
            if(f_isOperand(token)){
                out_s += token;
                state = EXPECT_OPERATOR;
            }else if(token == '(' || token == '~')
                opStack.push(token);
            else 
                return "error";
        }
        // Expecting a binary operator or ')'
        else if(state == EXPECT_OPERATOR){
            if(f_isBinaryOperator(token)){
                while(!opStack.empty() && f_shouldPop(opStack.top(), token)){
                    out_s += opStack.top();
                    opStack.pop();
                }
                opStack.push(token);
                state = EXPECT_OPERAND;
            }
            else if(token == ')'){
                while(!opStack.empty() && opStack.top() != '('){
                    out_s += opStack.top();
                    opStack.pop();
                }
                if(opStack.empty())
                    return "error";
                opStack.pop();
            }
            else 
                return "error";
        }
    }

    // Expression cannot end when an operand is still expected
    if(state == EXPECT_OPERAND)
        return "error";

    // Pop remaining operators from stack
    while(!opStack.empty()){
        char top = opStack.top();
        opStack.pop();
        if(top == '(')
            return "error";
        out_s += top;
    }

    return out_s;
}