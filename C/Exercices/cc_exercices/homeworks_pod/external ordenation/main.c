# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define PALAVRA 4

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

void preenche_arq(int *palavra, FILE *dados){
    FILE *temp = fopen("temp1.txt", "a");
    for(int i = 0; i < PALAVRA && !feof(dados); i++){
        fscanf(dados, "%d ", &palavra[i]);
        fprintf(temp, "%d ", palavra[i]);
    }
    fclose(temp);

    temp = fopen("temp2.txt", "a");
    for(int i = 0; i < PALAVRA && !feof(dados); i++){
        fscanf(dados, "%d ", &palavra[i]);
        fprintf(temp, "%d ", palavra[i]);
    }
    fclose(temp);

    temp = fopen("temp3.txt", "a");
    for(int i = 0; i < PALAVRA && !feof(dados); i++){
        fscanf(dados, "%d ", &palavra[i]);
        fprintf(temp, "%d ", palavra[i]);
    }
    fclose(temp);

    temp = fopen("temp4.txt", "a");
    for(int i = 0; i < PALAVRA && !feof(dados); i++){
        fscanf(dados, "%d ", &palavra[i]);
        fprintf(temp, "%d ", palavra[i]);
    }
    fclose(temp);

    temp = fopen("temp5.txt", "a");
    for(int i = 0; i < PALAVRA && !feof(dados); i++){
        fscanf(dados, "%d ", &palavra[i]);
        fprintf(temp, "%d ", palavra[i]);
    }
    fclose(temp);

    temp = fopen("temp6.txt", "a");
    for(int i = 0; i < PALAVRA && !feof(dados); i++){
        fscanf(dados, "%d ", &palavra[i]);
        fprintf(temp, "%d ", palavra[i]);
    }
    fclose(temp);

    temp = fopen("temp7.txt", "a");
    for(int i = 0; i < PALAVRA && !feof(dados); i++){
        fscanf(dados, "%d ", &palavra[i]);
        fprintf(temp, "%d ", palavra[i]);
    }
    fclose(temp);

    temp = fopen("temp8.txt", "a");
    for(int i = 0; i < PALAVRA && !feof(dados); i++){
        fscanf(dados, "%d ", &palavra[i]);
        fprintf(temp, "%d ", palavra[i]);
    }
    fclose(temp);
}

void ler_dados(int *a, char *arquivo){
    FILE *arq = fopen(arquivo, "r");
    int i = 0;
    while(fscanf(arq, "%d ", &a[i]) > 0){
        i++;
    }
    fclose(arq);
}

void escrever_dados(int *a, char *arquivo, int tam){
    FILE *arq = fopen(arquivo, "w");

    for(int i = 0; i < tam && !feof(arq); i++){
        fprintf(arq, "%d ", a[i]);
    }
    
    fclose(arq);
}


int main(){
    FILE *dados = fopen("dados.txt", "r");
    int array[PALAVRA];

    preenche_arq(array, dados);

    ler_dados(array, "temp1.txt");
    heapSort(array, PALAVRA);
    escrever_dados(array, "temp1.txt", PALAVRA);

    ler_dados(array, "temp2.txt");
    heapSort(array, PALAVRA);
    escrever_dados(array, "temp2.txt", PALAVRA);

    ler_dados(array, "temp3.txt");
    heapSort(array, PALAVRA);
    escrever_dados(array, "temp3.txt", PALAVRA);

    ler_dados(array, "temp4.txt");
    heapSort(array, PALAVRA);
    escrever_dados(array, "temp4.txt", PALAVRA);

    ler_dados(array, "temp5.txt");
    heapSort(array, PALAVRA);
    escrever_dados(array, "temp5.txt", PALAVRA);

    ler_dados(array, "temp6.txt");
    heapSort(array, PALAVRA);
    escrever_dados(array, "temp6.txt", PALAVRA);

    ler_dados(array, "temp7.txt");
    heapSort(array, PALAVRA);
    escrever_dados(array, "temp7.txt", PALAVRA);

    ler_dados(array, "temp8.txt");
    heapSort(array, PALAVRA);
    escrever_dados(array, "temp8.txt", PALAVRA);

    fclose(dados);
    return 0;
}