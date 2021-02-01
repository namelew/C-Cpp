# include <stdio.h>
// criando uma função que copia conteudo de um .txt e cola em outro
int main(void){
    void cope(FILE *file1, FILE *file2);

    FILE *file = fopen("teste.txt", "r");

    if (file == NULL){printf("Arquivo nao encontrado\n"); return 0;}

    FILE *copia = fopen("copia.txt", "w");

    cope(file, copia);

    fclose(file);
    fclose(copia);

    return 0;
}

void cope(FILE *file1, FILE *file2){
    char leitor[1000];
    while(fgets(leitor,1000, file1) != NULL){
        fputs(leitor, file2);
    }


}