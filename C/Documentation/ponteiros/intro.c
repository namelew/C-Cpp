# include <stdio.h>

int main(void){

    int x=10;

    int *ponteiro; // declarando um ponteiro
    ponteiro = &x; // utilizando o ponteiro

    printf("Valor: %i\n", x);
    printf("Endereco de Memoria: %i\n", &x); // &variavel devolve o endereço de memoria onde está a variável

    //ponteiro
    printf("Valor ponteiro: %i\n", *ponteiro); //retornando o valor
    printf("Endereco ponteiro: %i", ponteiro); // retornando o endereço

    return 0;
}