# include <stdio.h>
// passando matrizes como argumento para uma função
int main(void){
    int matriz[3][3] = {1,2,3,4,5,6,7,8,9};
    void print(int matriz[3][3]); // tanto matriz[3][3] quanto matriz[][3] são formatos válidos

    print(matriz);

    return 0;
}

void print(int matriz[3][3]){
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%i ", matriz[i][j]);
        }
        printf("\n");
    }

}