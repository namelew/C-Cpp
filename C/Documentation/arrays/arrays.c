# include <stdio.h>

int main(void){
    // int notas[5] = {0} para fazer todos elementos serem iguais a 0
    // int notas[5] = {5, 7, 2, 1, 6}; //criando o vetor e inserindo valores
    float notas[3] = {0};
    float total, media;
    printf("Digite as 3 notas do aluno:\n");
    for(int i = 0; i < 3; i++){
        scanf("%f", &notas[i]);
    }
    for(int i = 0; i < 3; i++){
        total += notas[i];
    }
    media = total/3;

    printf("A media do aluno eh %.2f\n", media);
}