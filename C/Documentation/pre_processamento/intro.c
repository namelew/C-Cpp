// Pré processamento
// Define métricas ao compilador antes da execução do programa propriamente dito
# include <stdio.h>

// essa linha disse ao compilador que o conjunto de caracteres "SIM" é = a 100
# define SIM 100
// essa linha disse ao compilador que o conjunto de caracteres "NAO" é = a -100
# define NAO -100

int main(void){
    int x;

    printf("Digite um numero inteiro: ");
    scanf("%i", &x);

    if (x <= 10){
        printf("%i", NAO);
    } else {
        printf("%i", SIM);
    }

    return 0;
}