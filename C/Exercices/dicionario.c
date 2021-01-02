# include <stdio.h>
// esse programa verifica se uma string extiste em uma struct e printa na tela sua definição, se ela existir
struct dicionario{
    char palavra[20], definion[50];
};

int main(void){
    int find_string(const struct dicionario languagem[], const char seach[], const int nwords);

    const int NDEFITIONS = 7;
    char palavra[20], caracter;
    int resulseach, i=0;

    const struct dicionario portuguese[7] = {
        {"pao","comida a base de trigo"},
        {"mortadela","comida a base de carne"},
        {"feijao","comida tipica brasileira"},
        {"tempero","coisas que sao colocadas dentro da comida"},
        {"queijo","coisa de mineiro"},
        {"macarronada","coisa de italiano"},
        {"pizza","coisa de italiano tambem, eles amam massa"}};

    printf("Read a word in portuguese: ");
    do{
        caracter = getchar();// função que pega qualquer caractere digitado pelo user e retorna
        palavra[i] = caracter;
        i++;
    }while(caracter != '\n');
    palavra[i-1] = '\0';

    resulseach = find_string(portuguese, palavra, NDEFITIONS);

    if (resulseach == -1){
        printf("Word not finded\n");
    } else{
        printf("Word: %s\nDefinition: %s", palavra, portuguese[resulseach].definion);
    }

    return 0;
}

_Bool compare_strings(const char palavra1[], const char palavra2[]){
    int i = 0;
    while(palavra1[i] == palavra2[i] && palavra1[i] != '\0' && palavra2[i] != '\0'){
        i++;
    }
    if(palavra1[i] == '\0' && palavra2[i] == '\0'){
        return 1;
    } else {
        return 0;
    }

}

int find_string(const struct dicionario languagem[], const char seach[], const int nwords){
    _Bool compare_strings(const char palavra1[], const char palavra2[]);
    int i=0;

    while(i < nwords){
        if(compare_strings(seach, languagem[i].palavra)){return i;}
        else{i++;}
    }
    return -1;

}