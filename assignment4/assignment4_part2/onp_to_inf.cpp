#include "onp_to_inf.h"
#include "helper_funcs.h"
#include "expr.h"
#include <string>
#include <stack>
#include <iostream>



// Builds text for unary '~' operator
std::string f_makeUnaryText(const Expr& child){
    if(child.priority < f_priority('~'))
        return "~(" + child.text + ")";
    else
        return "~" + child.text;
}

// Builds right side text and adds parentheses if needed
std::string f_makeRightText(const Expr& right, char op){
    if(right.priority < f_priority(op))
        return "(" + right.text + ")";
    else if(right.priority == f_priority(op) && 
    (op == '-' || op == '/' || op == '%' ||
     op == '<' || op == '>' || op == '=')){
        return "(" + right.text + ")";
     }
     else
        return right.text;
}

// Builds left side text and adds parentheses if needed
std::string f_makeLeftText(const Expr& left, char op){
    if(left.priority < f_priority(op))
        return "(" + left.text + ")";
    else if(left.priority == f_priority(op) && op == '^')
        return "(" + left.text + ")";
    else
        return left.text;
}

// Converts cleaned ONP expression to INF
// Returns "error" if expression is invalid
std::string f_onpToInf(const std::string& expr){
    std::stack<Expr> stack;
    
    for(char token: expr){
        // Push operand as a simple expression
        if(f_isOperand(token)){
            std::string token_str;
            token_str += token;
            Expr opExpr(token_str, 100, '\0',true);
            stack.push(opExpr);
        }
        // Unary operator needs one operand
        else if(token == '~'){
            if(stack.empty()){
                return "error";
            }
            Expr child = stack.top();
            stack.pop();
            std::string newUnText = f_makeUnaryText(child);
            Expr unExp(newUnText, f_priority('~'), '~', false);
            stack.push(unExp);

        }
        // Binary operator needs two operands
        else if(f_isBinaryOperator(token)){
            if(stack.size() < 2)
                return "error";

            Expr right = stack.top();
            stack.pop();
            
            Expr left = stack.top();
            stack.pop();

            std::string leftText = f_makeLeftText(left, token);
            std::string rightText = f_makeRightText(right, token);

            std::string newBinText = leftText + token + rightText;
            Expr binExp(newBinText, f_priority(token), token, false);
            stack.push(binExp);
        }
        else
            return "error";
    }

    // At the end only one final expression should remain
    if(stack.size() != 1)
        return "error";

    return stack.top().text;
}