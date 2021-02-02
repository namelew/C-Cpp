# include <stdio.h>
# include <stdlib.h>

int main(void){
    //int *p = (int *)malloc(sizeof(int));
    int *p = (int *)calloc(5, sizeof(int)); // calloc(q. elementos alocados, size_t)
    // calloc também limpa o lixo residual inicializando os espaços alocados com 0
    for(int i = 0; i < 5; i++){
        printf("Endereco de p%i: %p | Valor de p%i: %i\n", i, &p[i], i, *(p + i));
    }

    return 0;
}