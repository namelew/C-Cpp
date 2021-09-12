# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int main() {
    int quantidade = 1000;
    float input;
    while(quantidade > 0){
        printf("Total em estoque: %d L\n", quantidade);
        printf("Valor por litro: R$ 7,00\n");
        printf("Valor: R$ ");
        scanf("%f", &input);
        quantidade -= (int)input/7;
        if(quantidade > 0){
            printf("Compra efetuada com sucesso\n");
        }
    }
    printf("Expediente encerrado, reservatorio vazio\n");
    return 0;
}