# include <stdio.h>
# define PI 3.14159
# define DOIS_PI PI*2 // dá pra utilizar elementos já definidos em outros defines

/* Macro
    São funções definidas no pré processamento
*/
# define AREA_CIRCULO(raio) raio * raio * PI

int main(void){

    printf("%f\n", PI);
    printf("%f\n", DOIS_PI);
    printf("%f\n", AREA_CIRCULO(30));

    return 0;
}