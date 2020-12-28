# include <stdio.h>

int gVarGlobal = 2; // variáveis globais podem ser acessadas me qualquer ponto do programa

int main(void){
    void teste(void);

    printf("Variavel Global: %i\n", gVarGlobal); // Chamando a varGlobal no main()
    teste(); // perceba que a varlocal sempre é reiniciada
    teste(); // perceba que a varestatica muda de valor

    gVarGlobal++; // modificando ela no main()
    
    return 0;
}

void teste(void){

    // perde o valor toda vez que a função é chamada
    int varlocal = 2;
    varlocal *= 2;

    // Não perde o valor, e é chamada de variável estática
    static int varestatica = 2;
    varestatica *= 2;

    gVarGlobal *= 2; // Modificando no teste()

    printf("Variavel Local Automatica: %i\n", varlocal);
    printf("Variavel Local Estatica: %i\n", varestatica);
    printf("Variavel Global: %i\n", gVarGlobal); // Chamando a varGlobal no teste()
}