#include <stdio.h>

int main(){
    int i;

    scanf("%d", &i);

    switch (i){
        case 1:
            printf("Opcao 1\n");
            break;
        case 2:
            printf("Opcao 2\n");
            break;
        case 3:
            printf("Opcao 3\n");
            break;
        default: // Caso a variável não seja nenhum dos casos anteriores, ele executará as linhas abaixo
            printf("Opcao Invalida\n");
            break;
    }
    return 0;
}