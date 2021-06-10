#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *array, int n, int modo);
void bubble_sort_flag(int *array, int tam);

int main(){
    int array[9] = {7, 10, 5, 3, 8, 4, 2, 9, 6};
    int tam = sizeof(array)/sizeof(int);
    //int modo;
    //printf("Modo: ");
    //scanf("%d", &modo);

    //bubble_sort(array, tam, modo);
    bubble_sort_flag(array, tam);
    for(int i = 0; i < tam; i++){
        printf("array[%i] = %i\n", i, array[i]);
    }

    return 0;
}

void bubble_sort(int *array, int n, int modo){
    // duplicando o segundo maior valor
    // o modo 2, decrescente nao funciona
    int i, j, temp;
    if(modo){
        for(i = n; i > 1; i--){
            for(j = 0; j < i; j++){
                if(array[j] > array[j+1]){
                    temp = array[j+1];
                    array[j+1] = array[j];
                    array[j] = temp;
                }
            }
        }
    }else{
        for(i = n; i > 1; i--){
            for(j = 0; j < i; j++){
                if(array[j] < array[j+1]){
                    temp = array[j+1];
                    array[j+1] = array[j];
                    array[j] = temp;
                }
            }
        }
    }
}

void bubble_sort_flag(int *array, int tam){
    // duplicando o segundo maior valor
    int i, j, temp, flag;
    for(i = tam; i > 1; i--){
        flag = 0;
        for(j = 0; j < i; j++){
            if(array[j] > array[j+1]){
                temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
                flag = 1;
            }
        }
        if(!flag){
            break;
        }
    }
}