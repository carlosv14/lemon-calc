
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculadoraparser.h"

void* ParseAlloc(void* (*allocProc)(size_t));
void* Parse(void*, int, const char*);
void* ParseFree(void*, void(*freeProc)(void*));

int yylex(void);
extern char * yytext;
extern FILE * yyin;

int main(int argc, char *argv[]){
    if(argc != 2){
        fprintf(stderr, "No file provided %s\n", argv[0]);
    }

    FILE * f = fopen(argv[1], "r");
    if(f == NULL){
        fprintf(stderr, "Could not read file%s\n", argv[1]);
    }

    yyin = f;

    void * parser = ParseAlloc(malloc);
    int lexCode;
    
    do{
        lexCode = yylex();
        Parse(parser, lexCode, strdup(yytext));
    }while(lexCode > 0);

    if(lexCode == -1){
        fprintf(stderr, "Lexer found and error\n");
    }

    ParseFree(parser, free);
    return 0;
}