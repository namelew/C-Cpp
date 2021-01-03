# include <stdio.h>

int main(void){

    int x = 10;
    double y = 10.5;
    char z = 'z';

    int *pX = &x;
    double *pY = &y;
    char *pZ = &z;

    int *resultado;
    resultado = 6422284; // ponteiros também podem armazenar os endereços diretamente

    printf("Endereco de X: %i - Valor de X: %i\n", pX, *pX);
    printf("Endereco de Y: %i - Valor de Y: %.2lf\n", pY, *pY);
    printf("Endereco de Z: %i - Valor de Y: %c\n", pZ, *pZ);

    printf("Valor de Resultado: %i", *resultado);

    return 0;
}