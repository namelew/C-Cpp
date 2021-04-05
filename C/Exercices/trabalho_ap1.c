#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define E 2.7182 // definindo a constante de euler

double f(double x);
int valor_intermediario(double inter[], double apro);

int main(){
    double intervalo[2];

    printf("Insira as coordenadas(formato: a b)): ");
    scanf("%lf %lf", &intervalo[0], &intervalo[1]);

    while(!valor_intermediario(intervalo, 0.09)){
        printf("Nao eh possivel afirmar que existe solucao neste intervalo, tente outros dois numeros\n");
        printf("Insira as coordenadas(formato: a b): ");
        scanf("%lf %lf", &intervalo[0], &intervalo[1]);
    }

    printf("A equacao tem pelo menos uma solucao neste intervalo(%.2lf, %.2lf)\n", intervalo[0], intervalo[1]);
    
    return 0;
}

double f(double x){
    // implementado a formula
    return 3 - 2*pow(x,2) - pow(E, x); // 3 - 2x^2 - e^x
}

int valor_intermediario(double inter[], double apro){
    // calculando valor intermediario
    // 0 = falso, 1=verdadeiro
    double temp;
    if(inter[0] < inter[1]){
        temp = inter[0];
        inter[0] = inter[1];
        inter[1] = temp;
    }
    if(inter[0] == inter[1] || f(inter[0])*f(inter[1]) > 0){
        // verificando se existe raiz
        return 0;
    }
    while(abs(abs(f(inter[0])) - abs(f(inter[1]))) > apro){
        // aplicando a aproximação de 10^-1
        inter[0] -= 0.01;
        inter[1] -= 0.01;
    }
    return 1;
}