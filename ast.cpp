#include "ast.h"

float NumExpr::eval(){
    return this->value;
}

float AddExpr::eval(){
    float res = this->expr1->eval() + this->expr2->eval();
    printf("= %f\n", res);
    return res;
}

float SubExpr::eval(){
    float res = this->expr1->eval() - this->expr2->eval();
    printf("= %f\n", res);
    return res;
}

float MulExpr::eval(){
    float res = this->expr1->eval() * this->expr2->eval();
    printf("= %f\n", res);
    return res;
}

float DivExpr::eval(){
    float res = this->expr1->eval() / this->expr2->eval();
    printf("= %f\n", res);
    return res;
}

map<string, float> vars = {};
map<string, MethodDefinition*> methods = {};


void addVariable(string id, Expr * expr){
    vars[id] = expr->eval();
}

void addMethod(string id, MethodDefinition * md){
    methods[id] = md;
}

float MethodInvocation::eval(){
    MethodDefinition * md =methods[this->id];
    list<string>::iterator it = md->params.begin();
    list<Expr *>::iterator exprIt = this->expressions.begin();
    while(it != md->params.end()){
        addVariable((*it).c_str(), (*exprIt));
        it++;
        exprIt++;
    }

    list<Expr *>::iterator stmts = md->expressions.begin();
    while(stmts != md->expressions.end()){
        (*stmts)->eval();
        stmts++;
    }

    return 0;
}

float IdExpr::eval(){
    return vars[this->value];
}