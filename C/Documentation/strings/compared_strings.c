# include <stdio.h>

int main(void){
    _Bool stringsIguais(char s1[], char s2[]);
    char string1[20], string2[20];

    printf("Digite duas strings(s1 s2): ");
    scanf("%s %s", &string1, &string2);

    if (stringsIguais(string1, string2)){
        printf("As strings sao iguais\n");
    } else {
        printf("As strings nao sao iguais\n");
    }

    return 0;
}

_Bool stringsIguais(char s1[], char s2[]){
    int i=0;

    while(s1[i] == s2[i] && s2[i] != '\0' && s1[i] != '\0'){
        i++;
    }
    if(s1[i] == '\0' && s2[i] == '\0'){
        return 1;
    } else {
        return 0;
    }
}