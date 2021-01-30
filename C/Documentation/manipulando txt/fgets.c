# include <stdio.h>
// cuidado, essa função converte tudo em char
int main(void){
    FILE *file;
    file = fopen("teste.txt", "r");

    if(file == NULL){
        printf("Arquivo não encontrado!");
        return 0;
    }
    char frase[100];

    // o while existe para burlar a deficiencia de fgets
    // Ela lê uma string até encontrar uma quebra de pagína
    while (fgets(frase, 100, file) != NULL){
        printf("%s", frase);
    }

    fclose(file);

    return 0;
}