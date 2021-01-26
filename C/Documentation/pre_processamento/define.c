# include <stdio.h>

# define PI 3.14159 // definindo o valor de pi
# define NULO 0 // definiu um valor para NULO

int main(void){

    double areaCirculo(double raio);

    double r;
    int i = 3;

    while (i != NULO){
        printf("Digite o raio do circulo: ");
        scanf("%lf", &r);
        printf("A area do circulo eh %.2lf\n", areaCirculo(r));
        --i;
    }

    return 0;
}

double areaCirculo(double raio){
    return raio * raio * PI;
}