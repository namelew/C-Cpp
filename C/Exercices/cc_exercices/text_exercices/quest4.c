# include <stdlib.h>
# include <stdio.h>

typedef struct{
    char nome[50];
    float n1;
    float n2;
}Aluno;

int main(){
    FILE *arq = fopen("alunos.txt", "r");
    int i, tam;
    Aluno a[7];

    fscanf(arq, "%d\n", &tam);

    for(i = 0; i < tam; i++){
        fscanf(arq, "%[^\n]", &a[i].nome);
        fscanf(arq, "%f\n", &a[i].n1);
        fscanf(arq, "%f\n", &a[i].n2);
    }
    fclose(arq);

    arq = fopen("alunos_binario.txt", "wb");
    fwrite(a, sizeof(Aluno), tam, arq);
    fclose(arq);

    Aluno ba[tam];

    arq = fopen("alunos_binario.txt", "rb");
    fread(ba, sizeof(Aluno), tam, arq);

    for(i = 0; i < tam; i++){
        printf("Nome: %s - Nota 1: %.2f - Nota 2: %.2f\n", ba[i].nome, ba[i].n1, ba[i].n2);
    }
    fclose(arq);
    return 0;
}