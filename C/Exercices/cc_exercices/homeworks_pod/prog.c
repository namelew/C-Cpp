# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void ordem_crescente(int *array, int tam){
    for(int i = 0; i < tam; i++){
        array[i] = i;
    }
}

void ordem_descrecente(int *array, int tam){
    for(int i = tam-1; i >= 0; i--){
        array[i] = i;
    }
}

void random(int *array, int tam){
    srand(time(0));
    for(int i = 0; i < tam; i++){
        array[i] = rand();
    }
}

void troca(int *a, int j){
    int temp = a[j+1];
    a[j+1] = a[j];
    a[j] = temp;
}

void troca_s(int *array, int posmenor, int i){
    int temp = array[i];
    array[i] = array[posmenor];
    array[posmenor] = temp;
}

void bubble_sort_flag(int *array, int tam){
    // arrumar
    int i, j, flag;
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

void insert_sort(int *array, int tam){
    int i, j, p;
    for(i = 1; i < tam; i++){
        p = array[i];
        for(j = i; j >= 1 && p <array[j-1]; j--){
            array[j] = array[j-1];
        }
        array[j] = p;
    }
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
        troca_s(array, posmenor, i);
    }

}

void teste_bsort(int *array, int tam){
    clock_t start, end;

    start = clock();

    bubble_sort_flag(array, tam);
    
    end = clock();

    double difTempo = ((double) end - start)/CLOCKS_PER_SEC;

    printf("Bubble Sort[%i]:\nTempo em s: %.5lf\nTempo em ms: %.5lf\n\n", tam, difTempo, difTempo*1000);
}

void teste_selsort(int *array, int tam){
    clock_t start, end;

    start = clock();

    selection_sort(array, tam);
    
    end = clock();

    double difTempo = ((double) end - start)/CLOCKS_PER_SEC;

    printf("Selection Sort[%i]:\nTempo em s: %.5lf\nTempo em ms: %.5lf\n\n", tam, difTempo, difTempo*1000);
}

void teste_isort(int *array, int tam){
    clock_t start, end;

    start = clock();

    insert_sort(array, tam);
    
    end = clock();

    double difTempo = ((double) end - start)/CLOCKS_PER_SEC;

    printf("Insert Sort[%i]:\nTempo em s: %.5lf\nTempo em ms: %.5lf\n\n", tam, difTempo, difTempo*1000);
}

int main(){
    int array10[10000];
    int array50[50000];
    int array100[100000];
    
    printf("Teste em Array Ordenados em Ordem Crescente:\n");
    ordem_crescente(array10, 10000);
    ordem_crescente(array100, 100000);
    ordem_crescente(array50, 50000);

    teste_bsort(array10, 10000);
    teste_bsort(array50, 50000);
    teste_bsort(array100, 100000);

    teste_selsort(array10, 10000);
    teste_selsort(array50, 50000);
    teste_selsort(array100, 100000);

    teste_isort(array10, 10000);
    teste_isort(array50, 50000);
    teste_isort(array100, 100000);
    
    printf("\nTeste em Array Ordenados em Ordem Decrescente:\n");
    ordem_descrecente(array10, 10000);
    ordem_descrecente(array50, 50000);
    ordem_descrecente(array100, 100000);

    teste_bsort(array10, 10000);
    teste_bsort(array50, 50000);
    teste_bsort(array100, 100000);
    
    teste_selsort(array10, 10000);
    teste_selsort(array50, 50000);
    teste_selsort(array100, 100000);

    teste_isort(array10, 10000);
    teste_isort(array50, 50000);
    teste_isort(array100, 100000);
    
    printf("\nTeste em Array Desordenados:\n");
    random(array10, 10000);
    random(array50, 50000);
    random(array100, 100000);

    teste_bsort(array10, 10000);
    teste_bsort(array50, 50000);
    teste_bsort(array100, 100000);

    teste_selsort(array10, 10000);
    teste_selsort(array50, 50000);
    teste_selsort(array100, 100000);

    teste_isort(array10, 10000);
    teste_isort(array50, 50000);
    teste_isort(array100, 100000);
    
    return 0;
}