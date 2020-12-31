# include <stdio.h>

int main(void){
    int vetor[10] = {6, 4, 1, 9, 8, 0, 5, 7, 3, 2}, i;
    void sortSimples(int vetor[], int n);

    sortSimples(vetor, 10);

    for(i = 0; i < 10; i++){
        printf("%i ", vetor[i]);
    }
    printf("\n");
    
    return 0;
}

void sortSimples(int vetor[], int n){
    int i, j, temp;
    for (i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if(vetor[i] > vetor[j]){
                temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }

}