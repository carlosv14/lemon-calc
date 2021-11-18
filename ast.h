#ifndef _AST_H_
#define _AST_H_

#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <list>
#include <string>

using namespace std;

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

class IdExpr: public Expr{
    public:
        IdExpr(string value){
            this->value = value;
        }
        string value;
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

class MethodDefinition{
    public:
        MethodDefinition(string id, list<string> params, list<Expr *> expressions){
            this->id = id;
            this->params = params;
            this->expressions = expressions;
        }       

        string id;
        list<string> params;
        list<Expr *> expressions;
};

class MethodInvocation: public Expr{
    public:
        MethodInvocation(string id, list<Expr *> expressions){
            this->id = id;
            this->expressions = expressions;
        }       

        string id;
        list<Expr *> expressions;
        float eval();
};

void addVariable(string id, Expr * value);
void addMethod(string id, MethodDefinition * value);

#endif