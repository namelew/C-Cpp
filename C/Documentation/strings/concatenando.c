# include <stdio.h>

int main(void){
    void concatenarStrings(char string1[], int tan1, char string2[],int tan2, char string3[]);
    // inicializando sem informar o tamanho
    char palavra1[] = {'p', 'a', 'o', ' '};
    char palavra2[] = {'m', 'o', 'r', 't', 'a', 'd', 'e', 'l', 'a'};
    // informando o tamanho, mas não inserindo elementos(nesse caso, informar o tamanho é obrigatório)
    char palavraNova[13];
    int i;

    concatenarStrings(palavra1, 4, palavra2, 9, palavraNova);

    for(i = 0; i < 13; i++){
        printf("%c", palavraNova[i]);
    }
    return 0;
}
void concatenarStrings(char string1[], int tan1, char string2[],int tan2, char string3[]){
    // i varre as strings 1 e 2, é reinicado a cada ciclo, e j varre a string 3, não é reiniciado
    int i, j;
    for (i = 0; i < tan1; i++){
        string3[i] = string1[i];
        j++;
    }
    for (i = 0; i < tan2; i++){
        string3[j] = string2[i];
        j++;
    }

}