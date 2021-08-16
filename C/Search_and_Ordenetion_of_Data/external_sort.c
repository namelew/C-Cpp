/* 
Implementação da intercalação balanceada de N caminhos
Autor: Prof. Geomar Schreiner (2020)
Obs: 
-> para algumas combinacoes de tamanho de BLC_MEMORIA, N_VALUES e N_FILES, o programa buga devido a forma como foram calculados os blocos.
Teste com as combinacoes:  10-45-6; 10-36-2; 6-24-4; 6-24-2; 6-20-2; 3-12-2
-> N_FILES se refere ao numero de arquivos que serao usados para alocar as particoes iniciais, e nao ao numero total de arquivos permitidos 
-> os arquivos com extensao .aux sao arquivos temporarios e poderiam ser apagados pelo programa ao final do processo
    -> os arquivos 'arquivo-N.aux' sao resultado da etapa de classificacao (divisao das particoes)
    -> os arquivos 'merge-N-itM.aux' sao resultado das diversas etapas da intercacacao. 
        - Na teoria, sao reaproveitados os mesmos arquivos; neste exemplo, para fins didaticos, criamos um novo arquivo a cada intercacacao.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLC_MEMORIA 6
#define N_VALUES 20
#define N_FILES 2

struct agenda {
    char name[15];
    char address[30];
    int age;
};
typedef struct agenda Agenda;

/* prototipos das funcoes */
void externalSort(char *arqName);
FILE *combinaBlocos(FILE *arqEnt[], int blocoId, int iter);
void merge(Agenda *A, int p, int q, int r);
void mergeSort(Agenda *A, int p, int r);
void imprimeAgenda(Agenda *A, int n);
Agenda *geraDadoAleatorios(int n);


int main() {
    Agenda *mAg;  
    char *nomearq = "Agenda.dat"; // ou char nomeArq[]="Agenda.dat"
    FILE *arq;

    //Gera e grava os dados
    mAg = geraDadoAleatorios(N_VALUES);
    printf("\n\nAntes da ordenacao: \n");
    imprimeAgenda(mAg, N_VALUES);
    arq = fopen(nomearq, "w+b");
    fwrite(mAg, sizeof(Agenda), N_VALUES, arq);    
    free(mAg);
    fclose(arq);

    // chama ordenacao externa
    externalSort(nomearq);

    // le do arquivo ordenado para a memoria e exibe
    mAg = malloc(sizeof(Agenda) * N_VALUES);
    fseek(arq, 0, SEEK_SET);
    fread(mAg, sizeof(Agenda), N_VALUES, arq);
    printf("\n\n\nDepois da ordenacao: \n");
    imprimeAgenda(mAg, N_VALUES);

    return 0;
}

void mergeSort(Agenda *A, int p, int r) {
    if (p < r - 1) {
        int q = (int)(p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q, r);
        merge(A, p, q, r);
    }
}

void merge(Agenda *A, int p, int q, int r){ // funcao de intercalacao do mergesort em memoria principal
    int i, j, k;
    Agenda B[r - p];
    i = p;
    j = q;
    k = 0;
    while (i < q && j < r)
    {
        if (A[i].age <= A[j].age)
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    while (i < q)
        B[k++] = A[i++];
    while (j < r)
        B[k++] = A[j++];
    for (i = p; i < r; ++i)
        A[i] = B[i - p];
}

Agenda *geraDadoAleatorios(int n) {
    int i;
    Agenda *ag = (Agenda *)malloc(sizeof(Agenda) * n);
    srand(time(NULL)); // gera a semente aleatoria
    for (i = 0; i < n; i++) {
        ag[i].age = rand() % 100;
        snprintf(ag[i].name, sizeof(ag[i].name), "Pessoa %.2d", i);
        snprintf(ag[i].address, sizeof(ag[i].address), "End %.2d", i);
    }
    return ag;
}

void imprimeAgenda(Agenda *A, int n) {
    int i;
    printf("\n********** Agenda ************\n\n");
    for (i = 0; i < n; i++) {
        printf("Record %d: name: %s \taddress: %s \tage: %d \n", i, A[i].name, A[i].address, A[i].age);
    }
    printf("\n******************************\n\n");
}

void externalSort(char *arqName) {
    FILE *auxFiles[N_FILES];
    FILE *arq;
    Agenda *agBloco = malloc(sizeof(Agenda) * BLC_MEMORIA);
    int size;

    //Primeira fase: ler os dados e colocar nos diferentes arquivos (classificacao)
    arq = fopen(arqName, "r+b");
    for (int i = 0; i < N_FILES; i++) {
        char fileName[40];
        snprintf(fileName, 40, "%s-%d.aux", "arquivo", i+1);
        auxFiles[i] = fopen(fileName, "w+b");
    }

    size = fread(agBloco, sizeof(Agenda), BLC_MEMORIA, arq);
    int i = 0;
    while (size > 0) {
        // ordena bloco na memoria principal usando merge sort
        mergeSort(agBloco, 0, size);
        fwrite(agBloco, sizeof(Agenda), size, auxFiles[i % N_FILES]);
        i++;
        size = fread(agBloco, sizeof(Agenda), BLC_MEMORIA, arq);
    }

    int numBloco = (i + 1) / N_FILES; //numero total de blocos gravados dividido pelo numero de files.

    //Segunda fase: intercalação
    FILE **arquivosEntrada = auxFiles; // a primeira entrada sao os arquivos gerados pela etapa de classificacao
    FILE **arquivosSaida;
    int iteracao = 0;
    while (numBloco > 0) {
        arquivosSaida = (FILE **)malloc(sizeof(FILE *) * numBloco);
        for (int j = 0; j < numBloco; j++) {
            arquivosSaida[j] = combinaBlocos(arquivosEntrada, j + 1, iteracao);
        }
        numBloco = numBloco / N_FILES;
        iteracao++;
        arquivosEntrada = arquivosSaida; // a saida vira a entrada da proxima etapa
    }

    //Terminou intercalacoes; copia do ultimo arquivo de merge de volta para o arquivo inicial
    fseek(arq, 0, SEEK_SET);
    fseek(arquivosSaida[0], 0, SEEK_SET);
    size = fread(agBloco, sizeof(Agenda), BLC_MEMORIA, arquivosSaida[0]);
    while (size > 0) {
        fwrite(agBloco, sizeof(Agenda), size, arq);
        size = fread(agBloco, sizeof(Agenda), BLC_MEMORIA, arquivosSaida[0]);
    }
}

FILE *combinaBlocos(FILE *arqEnt[], int blocoId, int iter) {
    char fileName[40];
    snprintf(fileName, 40, "%s-%d-it%d.aux", "merge", blocoId, iter);
    FILE *resposta = fopen(fileName, "w+b");
    int i;
    int *counter = calloc(N_FILES, sizeof(int));

    for (i = 0; i < N_FILES; i++)
        fseek(arqEnt[i], (blocoId - 1) * BLC_MEMORIA * sizeof(Agenda), SEEK_SET); // desloca o cursor do arquivo para o inicio da coluna que esta sendo intercalada

    Agenda *auxRead = malloc(sizeof(Agenda) * N_FILES);

    int *lidos = calloc(N_FILES, sizeof(int));

    int bool = 1;
    while (bool) {
        int candidatoEscrita = -1;

        //Le um elemento de cada arquivo
        for (i = 0; i < N_FILES; i++) {
            int readSize = -1;
            if (!lidos[i] && counter[i] < (blocoId * BLC_MEMORIA * (iter + 1))) {
                readSize = fread(&auxRead[i], sizeof(Agenda), 1, arqEnt[i]);
                lidos[i]++;
            }
            if (readSize == 0) {
                lidos[i] = -1; // Nao leu ninguem; chegou ao final do arquivo
            }
            if (candidatoEscrita < 0 && lidos[i] > 0)
                candidatoEscrita = i;
        }

        for (i = 1; i < N_FILES; i++) {
            if (lidos[i] > 0)
                if (auxRead[i].age < auxRead[candidatoEscrita].age) { // compara para encontrar o menor dos registros e decidir quem sera copiado para a saida
                    candidatoEscrita = i;
                }
        }

        if (candidatoEscrita < 0) {
            break;
        }

        fwrite(&auxRead[candidatoEscrita], sizeof(Agenda), 1, resposta); // grava o menor elemento no arquivo de saida

        lidos[candidatoEscrita] = 0;
        counter[candidatoEscrita]++;

        int soma = 0, endedFiles = 0;
        for (i = 0; i < N_FILES; i++) {
            soma += counter[i];
            if (feof(arqEnt[i]))
                endedFiles++;
        }

        if (soma >= BLC_MEMORIA * N_FILES * (iter + 1)) { 
            bool = 0;
        }
    }

    return resposta;
}