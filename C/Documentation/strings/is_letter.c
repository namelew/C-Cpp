# include <stdio.h>

int main(void){
    void alfabetic(char caracter);
    char nome[20];
    int i = 0;

    printf("Digite uma palavra: ");
    scanf("%s", &nome);

    while(nome[i] != '\0'){
        alfabetic(nome[i]);
        i++;
    }

    return 0;
}

void alfabetic(char caracter){
    // função que verifica se determinada caracter é uma letra
    // comparando caracteres utilizando estruturas de controle
    if ((caracter >= 'a' && caracter <= 'z')||(caracter >= 'A' && caracter <= 'Z')){
        printf("%c eh uma letra\n", caracter);
    } else {
        printf("%c nao eh uma letra\n", caracter);
    }
}