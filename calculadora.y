%token_type {int}

%include{
    #include <iostream>
    #include "calculadora.h"    
}

%syntax_error{
    std::cout<<"Error!"<<std::endl;
}

start::= expr(A). {std::cout<<"Result= "<< A <<std::endl;}

expr(A)::= expr(B) ADD factor(C). {A = B + C;}
expr(A)::= expr(B) SUB factor(C). {A = B - C;}
expr(A)::= factor(B). {A = B;}

factor(A)::= factor(B) MUL term(C). {A = B * C;}
factor(A)::= factor(B) DIV term(C). {
    if(C!=0){
        A = B/C;
    }else{
        std::cout<<"Can't divide by 0"<<std::endl;
    }
}
factor(A)::= term(B). {A = B;}

term(A)::= INT(B).{A = B;}

