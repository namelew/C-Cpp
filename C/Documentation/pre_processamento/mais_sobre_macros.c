# include <stdio.h>

// macro que retorna o maior entre dois numeros
# define MAIOR(x,y) x > y ? x : y
// checa se um caracter eh uma letra minuscula
# define EH_MINUSCULO(char) char >= 'a' && char <= 'z'

int main(void){
    char x = 'A';

    if(EH_MINUSCULO(x)){
        printf("Eh minusculo\n");
    } else {
        printf("Nao eh minusculo\n");
    }

    printf("%i\n", MAIOR(200,50));

    return 0;
}