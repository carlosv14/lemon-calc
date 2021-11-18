%option noyywrap

%{
    #include "calculadoraparser.h"
%}

%%

"+" { return TK_ADD;}
"-" { return TK_SUB;}
"*" { return TK_MUL;}
"/" { return TK_DIV;}
"let" { return TK_LET;}
";" { return TK_SEMICOLON;}
"=" { return TK_EQUAL;}
"," { return TK_COMMA;}
"=>" { return TK_ARROW;}
"(" { return TK_LEFTPARENS;}
")" { return TK_RIGHTPARENS;}
[a-z]+ { return TK_ID; }
[0-9]+ { return TK_NUMBER;}
[\n] { return TK_EOL;}
[\t] {/* nothing */}
" " {/* nothing */}
. {printf("Invalid character '%c'\n", yytext[0]);}

%%