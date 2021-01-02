# include <stdio.h>

int main(void){
    /* a tabela ASCII é a tabela que relaciona carecteres e números, de forma a permitir
    ao compilador, trabalhar com strings, valores "não numéricos".
    Acessar o site para tabela completa: https://web.fe.up.pt/~ee96100/projecto/Tabela%20ascii.htm
    */
   int a = 130, b = 146;
   printf("%c fodas mas %c assim que se usa acentos e simbolos especiais como o %c dentro da linguagem C.", a, a,b); // convertendo decimal em caracter


    return 0;
}