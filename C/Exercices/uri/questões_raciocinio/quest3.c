# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int main(){
    int hotel[5][8];
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 8; j++){
            printf("Quantidade de Hospede Quarto[%d][%d]: ", i, j);
            scanf("%d", &hotel[i][j]);
            getchar();
        }
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 8; j++){
            printf("Quarto [%d][%d] = %d\n", i, j, hotel[i][j]);
        }
    }

    return 0;
}