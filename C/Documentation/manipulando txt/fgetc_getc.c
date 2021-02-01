# include <stdio.h>
// as funções servem para receber chars

int main(void){

    char x[100];

    FILE *file = fopen("teste.txt", "r");

    int i=0;
    // fgetc e getc fazem as mesmas coisas
    // lê uma char digitada pelo teclado
    // EOF significa end of file
    // faz executar até o final do arquivo
    while((x[i] = fgetc(file)) != EOF){
        ++i;
    }
    x[i] = '\0';

    printf("%s\n", x);

    return 0;
}