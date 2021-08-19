# include <stdio.h>
# include <stdlib.h>
# include <string.h>

//Pra funcionar num_res/esp_mem >= num_arq e num_res != esp_men

# define ESP_MEM 16
# define NUM_RES 31
# define NUM_ARQ 2

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

FILE *combinaBlocos(FILE *arqEnt[], int blocoId, int iter) {
    char fileName[40];
    snprintf(fileName, 40, "%s-%d-it%d.aux", "merge", blocoId, iter);
    FILE *resposta = fopen(fileName, "w+b");
    int i;
    int *counter = calloc(NUM_ARQ, sizeof(int));

    for (i = 0; i < NUM_ARQ; i++)
        fseek(arqEnt[i], (blocoId - 1) * ESP_MEM * sizeof(int), SEEK_SET); // desloca o cursor do arquivo para o inicio da coluna que esta sendo intercalada

    int auxRead[NUM_ARQ];

    int *lidos = calloc(NUM_ARQ, sizeof(int));

    int bool = 1;
    while (bool) {
        int candidatoEscrita = -1;

        //Le um elemento de cada arquivo
        for (i = 0; i < NUM_ARQ; i++) {
            int readSize = -1;
            if (!lidos[i] && counter[i] < (blocoId * ESP_MEM * (iter + 1))) {
                readSize = fread(&auxRead[i], sizeof(int), 1, arqEnt[i]);
                lidos[i]++;
            }
            if (readSize == 0) {
                lidos[i] = -1; // Nao leu ninguem; chegou ao final do arquivo
            }
            if (candidatoEscrita < 0 && lidos[i] > 0)
                candidatoEscrita = i;
        }

        for (i = 1; i < NUM_ARQ; i++) {
            if (lidos[i] > 0)
                if (auxRead[i] < auxRead[candidatoEscrita]) { // compara para encontrar o menor dos registros e decidir quem sera copiado para a saida
                    candidatoEscrita = i;
                }
        }
        
        if (candidatoEscrita < 0) {
            break;
        }

        fwrite(&auxRead[candidatoEscrita], sizeof(int), 1, resposta); // grava o menor elemento no arquivo de saida

        lidos[candidatoEscrita] = 0;
        counter[candidatoEscrita]++;

        int soma = 0, endedFiles = 0;
        for (i = 0; i < NUM_ARQ; i++) {
            soma += counter[i];
            if (feof(arqEnt[i]))
                endedFiles++;
        }

        if (soma >= ESP_MEM * NUM_ARQ * (iter + 1)) { 
            bool = 0;
        }
    }

    return resposta;
}

void externalSort(char *arqName) {
    FILE *auxFiles[NUM_ARQ];
    FILE *arq;
    int agBloco[ESP_MEM];
    int size;

    //Primeira fase: ler os dados e colocar nos diferentes arquivos (classificacao)
    arq = fopen(arqName, "r+b");
    for (int i = 0; i < NUM_ARQ; i++) {
        char fileName[40];
        snprintf(fileName, 40, "%s-%d.aux", "arquivo", i+1);
        auxFiles[i] = fopen(fileName, "w+b");
    }

    size = fread(&agBloco, sizeof(int), ESP_MEM, arq);
    int i = 0;
    while (size > 0) {
        // ordena bloco na memoria principal usando heap sort
        heapSort(agBloco, ESP_MEM);
        fwrite(&agBloco, sizeof(int), size, auxFiles[i % NUM_ARQ]);
        i++;
        size = fread(agBloco, sizeof(int), ESP_MEM, arq);
    }

    int numBloco = (i + 1) / NUM_ARQ; //numero total de blocos gravados dividido pelo numero de files.

    //Segunda fase: intercalação
    FILE **arquivosEntrada = auxFiles; // a primeira entrada sao os arquivos gerados pela etapa de classificacao
    FILE **arquivosSaida;
    int iteracao = 0;
    while (numBloco > 0) {
        arquivosSaida = (FILE **)malloc(sizeof(FILE *) * numBloco);
        for (int j = 0; j < numBloco; j++) {
            arquivosSaida[j] = combinaBlocos(arquivosEntrada, j + 1, iteracao);
        }
        numBloco = numBloco / NUM_ARQ;
        iteracao++;
        arquivosEntrada = arquivosSaida; // a saida vira a entrada da proxima etapa
    }
    //Terminou intercalacoes; copia do ultimo arquivo de merge de volta para o arquivo inicial
    fseek(arq, 0, SEEK_SET);
    fseek(arquivosSaida[0], 0, SEEK_SET);
    size = fread(agBloco, sizeof(int), ESP_MEM, arquivosSaida[0]);
    while (size > 0) {
        fwrite(agBloco, sizeof(int), size, arq);
        size = fread(agBloco, sizeof(int), ESP_MEM, arquivosSaida[0]);
    }
}

int main(){
    int array[31] = {5,28,10,40,35,7,12,2,21,11,29,27,9,38,8,49,3,15,13,30,17,46,18,36,1,4,34,16,19,22,20};

    FILE *arq = fopen("dados.txt", "w+b");
    fwrite(array, sizeof(int), NUM_RES, arq);
    fclose(arq);
    
    printf("Antes de Ordenar: \n");
    for(int i = 0; i < NUM_RES; i++){
        printf("%d ", array[i]);
    }
    printf("\n");

    externalSort("dados.txt");

    printf("Depois de Ordenar: \n");
    fseek(arq, 0, SEEK_SET);
    fread(array, sizeof(int), NUM_RES, arq);
    for(int i = 0; i < NUM_RES; i++){
        printf("%d ", array[i]);
    }

    return 0;
}