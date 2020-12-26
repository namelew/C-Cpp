# include <stdio.h>

int main(){
    int c, num, soma, vetor[10] = {0};

    scanf("%i", &num);
    soma = num;

    for(c = 0; c < 10; c++){
        vetor[c] = soma;
        soma = soma * 2;
    }
    for(c = 0; c < 10; c++){
        printf("N[%i] = %i\n", c, vetor[c]);
    }
    return 0;
}