# include <stdlib.h>
# include <stdio.h>

typedef struct{
    char nome[40];
    float n1;
    float n2;
}Aluno;

int main(){
    FILE *arq = fopen("alunos.txt", "r");
    int i, tam;
    Aluno a;
    float media;

    fscanf(arq, "%d\n", &tam);
    for(i = 0; i < tam; i++){
        fscanf(arq, "%[^\n]", &a.nome);
        fscanf(arq, "%f\n", &a.n1);
        fscanf(arq, "%f\n", &a.n2);
        media = (a.n1 + a.n2)/2;
        if(media < 7.0){
            printf("Nome: %s\nNota 1:%.2f\nNota 2:%.2f\n", a.nome, a.n1, a.n2);
        }
    }
    fclose(arq);
    return 0;
}