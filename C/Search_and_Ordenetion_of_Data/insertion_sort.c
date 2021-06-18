# include <stdio.h>
# include <stdlib.h>

// ok

void insert_sort(int *array, int tam);

int main(){
    int array[] = {7, 10, 5, 3, 8, 4, 2, 9, 6};
    int tam = sizeof(array)/sizeof(int);

    insert_sort(array, tam);

    for(int i = 0; i < tam; i++){
        printf("A[%i] = %i\n", i, array[i]);
    }

    return 0;
}

void insert_sort(int *array, int tam){
    // resolvido
    int i, j, p;
    for(i = 1; i < tam; i++){
        p = array[i];
        for(j = i; j >= 1 && p <array[j-1]; j--){
            array[j] = array[j-1];
        }
        array[j] = p;
    }
}