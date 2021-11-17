#ifndef _AST_H_
#define _AST_H_

#include <stdio.h>
#include <stdlib.h>

class Expr{
    public:
        virtual float eval() = 0;
};

class BinaryExpr: public Expr{
    public:
        BinaryExpr(Expr* expr1, Expr* expr2){
            this->expr1 = expr1;
            this->expr2 = expr2;
        }
        Expr* expr1;
        Expr* expr2;
};

class NumExpr: public Expr{
    public:
        NumExpr(const char* value){
            this->value = atof(value);
        }
        float value;
        float eval();
};

class AddExpr : public BinaryExpr{
    public:
        AddExpr(Expr* expr1, Expr* expr2): BinaryExpr(expr1, expr2){

        }
        float eval();
};

class SubExpr : public BinaryExpr{
    public:
        SubExpr(Expr* expr1, Expr* expr2): BinaryExpr(expr1, expr2){

        }
        float eval();
};

class MulExpr : public BinaryExpr{
    public:
        MulExpr(Expr* expr1, Expr* expr2): BinaryExpr(expr1, expr2){

        }
        float eval();
};

class DivExpr : public BinaryExpr{
    public:
        DivExpr(Expr* expr1, Expr* expr2): BinaryExpr(expr1, expr2){

        }
        float eval();
};

#endif