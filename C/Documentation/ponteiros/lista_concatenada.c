# include <stdio.h>

int main(void){
    // criação de uma struct lista
    struct lista{
        int valor;
        int *proximo;
    };
    struct lista m1, m2, m3;
    struct lista *gancho = &m1; // ganho funciona como um vinculo dos elementos dessa lista
    // valores dos elementos
    m1.valor = 10;
    m2.valor = 20;
    m3.valor = 30;
    // cada lista possui uma indicação de qual vai ser o elemento seguinte
    m1.proximo = &m2;
    m2.proximo = &m3;
    m3.proximo = (struct lista *)0; // o ultimo elemento é uma struct lista de valor nulo

    while(gancho != (struct lista*)0){ // enquanto não alcançar o valor nula faça
        printf("%i\n", gancho -> valor); // gancho apontar para o valor armazenada em .valor de cada elemento
        gancho = gancho -> proximo; // o endereço de memoria armazenado em gancho é alterado para o endereço do valor seguinte
    }

    return 0;
}