# include <stdio.h>
# include <stdlib.h>

int maior(int *a, int tam);
void couting_sort(int *a, int tam);

int main(){
    int array[] = {2, 3, 7, 1, 9, 32, 21, 19, 2};
    int tam = sizeof(array)/sizeof(int);

    printf("Array nao ordenado\n");
    for(int i = 0; i < tam;i++){
        printf("array[%i] = %i\n", i, array[i]);
    }

    couting_sort(array, tam);

    printf("Array ordenado\n");
    for(int i = 0; i < tam;i++){
        printf("array[%i] = %i\n", i, array[i]);
    }

    return 0;
}

int maior(int *a, int tam){
    int maior = a[0];
    for(int i = 0; i < tam; i++){
        if(a[i] > maior){
            maior = a[i];
        }
    }
    return maior;
}

void couting_sort(int *a, int tam){
    int k = maior(a, tam);
    int count[k+1];
    int aux[tam];

    for(int i = 0; i <= k; i++){
        count[i] = 0;
    }

    for(int i = 0; i < tam; i++){
        count[a[i]]++;
    }

    for(int i = 1; i <= k; i++){
        count[i] += count[i-1];
    }

    for(int i = tam-1; i >= 0; i--){
        count[a[i]] = count[a[i]] - 1;
        aux[count[a[i]]] = a[i];
    }

    for(int i = 0; i < tam; i++){
        a[i] = aux[i];
    }
}