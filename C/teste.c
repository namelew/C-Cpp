#include <stdio.h>
void main ()
{
    float base;
    float altura;
    double area;

    printf("Digite o valor da base e da altura do triangulo\n");
    scanf("%f %f",&base,&altura);
    area = 0.2 * (base + altura);
    printf("a area do triangulo e:\n%f",area);
    printf("\n %f ,%f",base,altura);
}