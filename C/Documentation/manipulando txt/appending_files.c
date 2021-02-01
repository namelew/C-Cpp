# include <stdio.h>

int main(void){
    FILE *file;
    file = fopen("teste.txt", "a"); // abrindo o arquivo em modo de adição

    if (file == NULL){
        printf("Arquivo nao encontrado\n");
        return 0;
    }

    fprintf(file, "Nova frase\n");

    char string[] = "Outra nova frase\n";

    fputs(string, file); // adicionando um vetor de caracteres a um arquivo

    char caracter = '3';
    fputc(caracter, file); // adicionando um caracter

    fclose(file);

    return 0;
}