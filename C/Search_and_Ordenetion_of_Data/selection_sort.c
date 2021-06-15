#include <stdio.h>
#include <stdlib.h>

void selection_sort(int *array, int tam);

int main(){
    int array[] = {7, 10, 5, 3, 8, 4, 2, 9, 6};
    int i, tam = sizeof(array)/sizeof(int);

    selection_sort(array,tam);

    for(i = 0; i < tam; i++){
        printf("A[%i] = %i\n", i, array[i]);
    }

    return 0;
}

void troca(int *array, int posmenor, int i){
    int temp = array[i];
    array[i] = array[posmenor];
    array[posmenor] = temp;
}

void selection_sort(int *array, int tam){
    int i, posmenor, j;

    for(i = 0; i < tam-1; i++){
        posmenor = i;
        for(j = i+1; j < tam; j++){
            if(array[posmenor] > array[j]){
                posmenor = j;
            }
        }
        troca(array, posmenor, i);
    }

}