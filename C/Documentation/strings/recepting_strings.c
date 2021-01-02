# include <stdio.h>

int main(void){
    char linha[100], caracter;
    int i = 0;
    // utilizando esse formato, ele irá receber qualquer quantidade de strings
    do{
        caracter = getchar();// função que pega qualquer caractere digitado pelo user e retorna
        linha[i] = caracter;
        i++;
    }while(caracter != '\n');
    linha[i-1] = '\0';

    printf("%s\n", linha);

    return 0;
}