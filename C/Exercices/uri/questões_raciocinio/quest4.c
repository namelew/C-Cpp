# include <stdio.h>
# include <math.h>
# include <stdlib.h>

int main(){
    double conta, tpagar;
    int np, i;

    printf("Conta: R$ ");
    scanf("%lf", &conta);
    printf("Quantidade pessoas: ");
    scanf("%d", &np);

    tpagar = conta/np;
    //printf("Valor a pagar por pessoa: %.2f\n", tpagar);

    //Desafio:
    double p[np], st = 0;
    for(i = 0; i < np; i++){
        p[i] = tpagar;
        st += tpagar;
    }
    p[i-1] = tpagar + ((st + (conta * 0.001)) - conta);

    for(i = 0; i < np; i++){
        printf("Valor a pagar pessoa %d: %.2lf\n", i+1 , p[i]);
    }


    return 0;
}