# include <stdio.h>
// Questão 1
// Organizando em ordem crescente 5 elementos de um vetor
// Essa é a forma mais simples e a com menor desempenho, comparado a outras
int main(){
    int c, array[5] = {0};
    void sort(int array[], int n);

    for (c = 0; c < 5; c++){
        scanf("%d", &array[c]);
    }

    sort(array, 5);

    for(c = 0; c < 5; c++){
        printf("%i ", array[c]);
    }
    printf("\n");

    return 0;
}

void sort(int array[], int n){

    int i, j, temp;

    for (i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if(array[i] > array[j]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

}