# include <stdio.h>

int main(void){
    // overflow é quando se tenta armanezar em uma variável um valor maior do que o seu limite
    // underflow é a mesma coisa só que com valores menores que o limite inferior
    short int x = 2147483647;
    short int y = -214783647;
    // perceba que os valores printados no terminal são diferentes dos armazenados nas variáveis
    printf("%i", x); 
    printf("%i", y);

    return 0;
}