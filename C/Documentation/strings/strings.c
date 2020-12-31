# include <stdio.h>
// strings sem a biblioteca string.h
int main(void){
    // Uma string é um conjunto de caracteres armazenado em um array
    char teste[] = {'b', 'r', 'a', 's', 'i', 'l'}; // criando uma string 

    int i;

    for(i=0; i <6; i++){
        printf("%c", teste[i]);
    }

    return 0;
}