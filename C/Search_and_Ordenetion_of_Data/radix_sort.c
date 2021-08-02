# include <stdio.h>
# include <stdlib.h>

void radix_sort(int *a, int tam);

int main(){
    int array[] = {2, 3, 7, 1, 9, 32, 21, 19, 2};
    int tam = sizeof(array)/sizeof(int);

    printf("Array nao ordenado\n");
    for(int i = 0; i < tam;i++){
        printf("array[%i] = %i\n", i, array[i]);
    }

    radix_sort(array, tam);

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

void counting_sort(int *a, int tam, int pos){
    int aux[tam];
    int count[10], i, digito;

    for(i = 0; i < 10; i++){
        count[i] = 0;
    }
    for(i = 0; i < tam; i++){
        digito = (a[i]/pos)%10;
        count[digito]++;
    }
    for(i = 1; i < 10; i++){
        count[i] += count[i-1];
    }
    for(i = tam-1; i >= 0; i--){
        digito = (a[i]/pos)%10;
        count[digito]--;
        aux[count[digito]] = a[i];
    }
    for(i = 0; i < tam; i++){
        a[i] = aux[i];
    }
}

void radix_sort(int *a, int tam){
    int max = maior(a, tam);
    for(int pos = 1; max/pos > 0; pos*=10){
        counting_sort(a, tam, pos);
    }
}