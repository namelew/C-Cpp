# include <stdlib.h>
# include <stdio.h>

int main(void){
    int *p = (int *) malloc(sizeof(int)); // alocando memória
    *p = 1000;

    printf("%i\n", *p);

    free(*p); // desalocando memória
    // desaloca a memória, mas o valor "1000" continua como lixo residual

    int *m = (int *) malloc(sizeof(int));
    printf("%i\n", *m);

    return 0;
}