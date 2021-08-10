# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main(){
    FILE *arq = fopen("quest1.txt", "r");

    int cg=0, wes=0, lb=0;
    char ch;

    while(!feof(arq)){
        ch = fgetc(arq);
        if(ch == ' '){
            wes++;
        }
        if(ch == '\n'){
            lb++;
        }
        cg++;
    }

    printf("Caracteres no geral: %i\nEspacos em branco: %i\nQuebras de linha: %i\n", cg, wes, lb);
    fclose(arq);
    return 0;
}