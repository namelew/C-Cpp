#include <stdio.h>
int main(){
    int contador, num = 1, soma;
    for (contador=1;contador<=10;contador++){
        soma = num + contador;
        printf("%i + %i = %i\n",num, contador, soma);
    }
    return 0;
}