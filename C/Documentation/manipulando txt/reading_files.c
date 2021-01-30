# include <stdio.h>
// lendo valores de um arquivo .txt
int main(void){
    FILE *file;

    file = fopen("teste.txt", "r");
    // garantindo que o programa só será executado se o arquivo não existir
    if(file == NULL){
        printf("O arquivo nao existe\n");
    } else {
        int x,y,z;

        fscanf(file, "%i %i %i", &x, &y, &z);

        printf("Foi %i %i %i", x, y, z);

        fclose(file);
    }

    return 0;
}