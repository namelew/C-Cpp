# include <stdio.h>

int main(void){
    void testeVariavel(int x);
    void testePonteiro(int *x);

    int teste = 1;
    int *pteste = &teste;

    //testeVariavel(teste); // cria uma copia e modifica a copia
    testePonteiro(pteste); // modifica o valor de teste diretamente

    printf("%i\n",teste);

    return 0;
}

void testeVariavel(int x){
    ++x;
}

void testePonteiro(int *Px){
    ++*Px;
}