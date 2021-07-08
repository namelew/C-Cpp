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

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int *array, int inicio, int fim)
{
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
 
        mergeSort(array, inicio, meio);
        mergeSort(array, meio + 1, fim);
 
        merge(array, inicio, meio, fim);
    }
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
int partition (int array[], int inicio, int fim)
{
    int pivot = array[fim]; 
    int i = (inicio - 1);
 
    for (int j = inicio; j <= fim - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[fim]);
    return (i + 1);
}
 
void quickSort(int array[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int pi = partition(array, inicio, fim);
 
        quickSort(array, inicio, pi - 1);
        quickSort(array, pi + 1, fim);
    }
}

void heapify(int arr[], int n, int i)
{
    int temp;
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2; 
 
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i) {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
 
        heapify(arr, n, largest);
    }
}
 
void heapSort(int arr[], int n)
{
    int temp;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    for (int i = n - 1; i > 0; i--) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
 
        heapify(arr, i, 0);
    }
}

void teste_msort(int *array, int tam){
    clock_t start, end;

    start = clock();

    mergeSort(array, 0, tam-1);
    
    end = clock();

    double difTempo = ((double) end - start)/CLOCKS_PER_SEC;

    printf("Merge Sort[%i]:\nTempo em s: %.5lf\nTempo em ms: %.5lf\n\n", tam, difTempo, difTempo*1000);
}

void teste_qsort(int *array, int tam){
    clock_t start, end;

    start = clock();

    quickSort(array, 0, tam-1);
    
    end = clock();

    double difTempo = ((double) end - start)/CLOCKS_PER_SEC;

    printf("Quick Sort[%i]:\nTempo em s: %.5lf\nTempo em ms: %.5lf\n\n", tam, difTempo, difTempo*1000);
}

void teste_hsort(int *array, int tam){
    clock_t start, end;

    start = clock();

    heapSort(array, tam);
    
    end = clock();

    double difTempo = ((double) end - start)/CLOCKS_PER_SEC;

    printf("Heap Sort[%i]:\nTempo em s: %.5lf\nTempo em ms: %.5lf\n\n", tam, difTempo, difTempo*1000);
}

int main(){
    int array10[10000];
    int array50[50000];
    int array100[100000];
    
    printf("Teste em Array Ordenados em Ordem Crescente:\n");
    ordem_crescente(array10, 10000);
    ordem_crescente(array100, 100000);
    ordem_crescente(array50, 50000);

    teste_msort(array10, 10000);
    teste_msort(array50, 50000);
    teste_msort(array100, 100000);

    teste_qsort(array10, 10000);
    teste_qsort(array50, 50000);
    teste_qsort(array100, 100000);

    teste_hsort(array10, 10000);
    teste_hsort(array50, 50000);
    teste_hsort(array100, 100000);
    
    printf("\nTeste em Array Ordenados em Ordem Decrescente:\n");
    ordem_descrecente(array10, 10000);
    ordem_descrecente(array50, 50000);
    ordem_descrecente(array100, 100000);

    teste_msort(array10, 10000);
    teste_msort(array50, 50000);
    teste_msort(array100, 100000);
    
    teste_qsort(array10, 10000);
    teste_qsort(array50, 50000);
    teste_qsort(array100, 100000);

    teste_hsort(array10, 10000);
    teste_hsort(array50, 50000);
    teste_hsort(array100, 100000);
    
    printf("\nTeste em Array Desordenados:\n");
    random(array10, 10000);
    random(array50, 50000);
    random(array100, 100000);

    teste_msort(array10, 10000);
    teste_msort(array50, 50000);
    teste_msort(array100, 100000);

    teste_qsort(array10, 10000);
    teste_qsort(array50, 50000);
    teste_qsort(array100, 100000);

    teste_hsort(array10, 10000);
    teste_hsort(array50, 50000);
    teste_hsort(array100, 100000);
    
    return 0;
}