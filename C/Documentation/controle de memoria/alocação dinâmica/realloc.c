# include <stdlib.h>
# include <stdio.h>

int main(void){
    int *p = (int*)malloc(sizeof(int) * 3);// alocando memoria

    printf("Tamanho de p: %i\n", sizeof(p));

    p = (int *)realloc(p, 32); // realoca a quantidade memória de p, tanto para mais quanto para menos
    // bom para diminuir o número de objetos e a função retorna uma copia do ponteiro com o novo tamanho de memória

    printf("Novo tamanho de p: %i", sizeof(p));

    return 0;
}