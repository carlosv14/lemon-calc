%token_type {const char *}
%token_prefix {TK_}

%left ADD SUB.
%left DIV MUL.

%include{
    #include "calculadoraparser.h"
    #include "ast.h"
}

%type expr {Expr*}
%type id_list {list<string> *}
%type expr_list {list<Expr *> *}

%syntax_error{
    printf("Error!\n");
}

start::= list_expr.

list_expr::= .
list_expr::= list_expr statement EOL.
list_expr::= list_expr EOL.

statement::= expr(expr). {expr->eval();}
statement::= var_definition.
statement::= method_definition.

var_definition::= LET ID(id) EQUAL expr(expr). { addVariable(id, expr);  printf("Defined var %s\n", id);}

method_definition::= LET ID(id) LEFTPARENS id_list(params) RIGHTPARENS ARROW expr_list(exprs).{
        MethodDefinition * md = new MethodDefinition(id, *params, *exprs);
        addMethod(id, md);
        printf("Defined method %s\n", id);
}

expr_list(exprlist)::= expr_list(existing) SEMICOLON expr(newexpr). {exprlist = existing; exprlist->push_back(newexpr);}
expr_list(exprs)::= expr(expr). {exprs = new list<Expr *>; exprs->push_back(expr);}

id_list(ids)::= id_list(existing) COMMA ID(newid). {ids = existing; ids->push_back(newid);}
id_list(ids)::= ID(id). {ids = new list<string>; ids->push_back(id);}

expr(expr)::= expr(left) ADD expr(right). {expr = new AddExpr(left, right);}
expr(expr)::= expr(left) SUB expr(right). {expr = new SubExpr(left, right);}
expr(expr)::= expr(left) MUL expr(right). {expr = new MulExpr(left, right);}
expr(expr)::= expr(left) DIV expr(right). {expr = new DivExpr(left, right);}
expr(expr)::=  NUMBER(num). {expr = new NumExpr(num);}
expr(expr)::= ID(id). {expr = new IdExpr(id);}
expr(expr)::= ID(id) LEFTPARENS expr_list(exprs) RIGHTPARENS. {expr = new MethodInvocation(id, *exprs);}


