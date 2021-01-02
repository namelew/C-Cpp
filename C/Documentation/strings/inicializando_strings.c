# include <stdio.h>

int main(void){
    // inicializando uma string
    // forma 1:
    char forma1[6] = {'B','r','a','s','i','l'};
    // forma 2:
    char forma2[] = {'B', 'r', 'a','s','i','l'};
    // forma 3:
    char forma3[7] = {"Brasil"};
    // forma 4:
    char forma4[] = {"Brasil"};
    // forma 5:
    char forma5[] = "Brasil";

    // forma alternativa de se fazer um print de uma string
    printf("%s", forma5);
    /* as formas 1 e 2 darão erro por causa do caracter nulo("\0") que existe no C.
    Cada string, vem por default com o caracter \0 no final dela e caso não exista
    espaço para ele, o compilador dará um erro. Nos casos 3, 4 e 5, o compilador i_
    rá inserir o caracter nulo automáticamente ao ser executado*/

    // o caracter nulo serve para indicar o fim da string


    return 0;
}