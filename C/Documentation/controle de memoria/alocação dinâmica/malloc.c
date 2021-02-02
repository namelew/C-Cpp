# include <stdio.h>
# include <stdlib.h>

void main(void){

    int *p = (int *) malloc(sizeof(int)); // malloc aloca uma quantidade de bytes da memória RAM para ser usado posteriormente
    // malloc sempre retorna um ponteiro void - void *
    // malloc não remove o lixo da memoria
    // se malloc não consegui alocar memoria, ela retornara NULL
    // size_t é um tipo de dado, que é sempre inteiro positivo
    if (p == NULL){
        printf("Nao foi possivel alocar memoria para o programa");
    }

    *p = 1000;

    printf("%i", *p);

}