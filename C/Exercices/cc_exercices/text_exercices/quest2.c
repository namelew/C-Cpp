# include <stdlib.h>
# include <stdio.h>

void sort(int *array, int tam);

int main(){
    FILE *arq = fopen("numeros.txt", "r");
    int array[20], i = 0;
    while(fscanf(arq, ",%d", &array[i]) > 0){
        i++;
    }
    fclose(arq);

    arq = fopen("numeros_ord.txt", "a");
    sort(array, 20);

    for(i=0; i<20; i++){
        fprintf(arq, "%d,", array[i]);
    }
    fclose(arq);
    return 0;
}

void troca(int *a, int j){
    int temp = a[j+1];
    a[j+1] = a[j];
    a[j] = temp;
}

void sort(int *array, int tam){
    int i, j, temp, flag;
    for(i = tam; i > 1; i--){
        flag = 0;
        for(j = 0; j < i-1; j++){
            if(array[j] > array[j+1]){
                troca(array, j);
                flag = 1;
            }
        }
        if(!flag){
            break;
        }
    }
}