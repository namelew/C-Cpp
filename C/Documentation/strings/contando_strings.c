# include <stdio.h>

int main(void){
    char user_string[20];
    int conta_string(char string[]);

    printf("Digite uma palavra: ");
    scanf("%s", &user_string);

    int tam = conta_string(user_string);

    printf("A string %s possui %i caracteres\n", user_string, tam);

    return 0;
}

int conta_string(char string[]){
    // o caracter nulo é contado também
    int i=0;
    do {
        i++;
    } while(string[i] != '\0');

    return i+1;
}