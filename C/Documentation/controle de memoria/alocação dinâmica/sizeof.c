# include <stdio.h>
# include <stdlib.h>
// sizeof() - retorna o tamanho em bytes de determinda estrutura

struct x{
    int a;
    double b;
    int c;
};

int main(void){
    int array[10];
    struct x estrutura;

    printf("%li\n", sizeof(array));
    printf("%li\n", sizeof(estrutura));

    return 0;
}