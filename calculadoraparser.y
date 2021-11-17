%token_type {const char *}
%token_prefix {TK_}

%left ADD SUB.
%left DIV MUL.

%include{
    #include "calculadoraparser.h"
    #include "ast.h"
}

%type expr {Expr*}

%syntax_error{
    printf("Error!\n");
}

start::= list_expr.

list_expr::= .
list_expr::= list_expr expr(expr) EOL. {printf("= %f\n", expr->eval());}
list_expr::= list_expr EOL.

expr(expr)::= expr(left) ADD expr(right). {expr = new AddExpr(left, right);}
expr(expr)::= expr(left) SUB expr(right). {expr = new SubExpr(left, right);}
expr(expr)::= expr(left) MUL expr(right). {expr = new MulExpr(left, right);}
expr(expr)::= expr(left) DIV expr(right). {expr = new DivExpr(left, right);}
expr(expr)::=  NUMBER(num). {expr = new NumExpr(num);}


