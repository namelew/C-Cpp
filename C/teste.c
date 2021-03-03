#include <stdio.h>
 
int main() {
    double salario, ajuste;
    
    scanf("%lf", &salario);
    
    if(salario <= 400){
        ajuste = 0.15;
    }
    if (salario <= 800 && salario > 400){
        ajuste = 0.12;
    }
    if(salario <= 1200 && salario > 800){
        ajuste = 0.10;
    }
    if(salario <= 2000 && salario > 1200){
        ajuste = 0.07;
    }
    if(salario > 2000){
        ajuste = 0.04;
    }
    
    printf("Novo salario: %.2lf\n", salario * (1.0+ajuste));
    printf("Reajuste ganho: %.2lf\n", salario * ajuste);
    printf("Em percentual: %.0lf %% \n", ajuste * 100);
    
    return 0;
}