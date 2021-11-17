%option noyywrap

%{
    #include "calculadoraparser.h"
%}

%%

"+" { return TK_ADD;}
"-" { return TK_SUB;}
"*" { return TK_MUL;}
"/" { return TK_DIV;}
[0-9]+ { return TK_NUMBER;}
[\n] { return TK_EOL;}
[\t] {/* nothing */}
. {printf("Invalid character '%c'\n", yytext[0]);}

%%