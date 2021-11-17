#include "ast.h"

float NumExpr::eval(){
    return this->value;
}

float AddExpr::eval(){
    return this->expr1->eval() + this->expr2->eval();
}

float SubExpr::eval(){
    return this->expr1->eval() - this->expr2->eval();
}

float MulExpr::eval(){
    return this->expr1->eval() * this->expr2->eval();
}

float DivExpr::eval(){
    return this->expr1->eval() / this->expr2->eval();
}