# include <stdio.h>
# include <stdlib.h>

typedef struct Veiculo{
    char nome[50];
    int ano;
}Veiculo;

void radix_sort(Veiculo *a, int tam);

int main(){
    Veiculo veiculos[15] = {
        {"Corsa",2008},
        {"Xevete",1997},
        {"Mustange",2011},
        {"Ferrari", 1980},
        {"Fox Ret", 2014},
        {"Classic", 2008},
        {"Uno", 2020},
        {"Clear", 2011},
        {"BMW", 1978},
        {"Camaro", 1992},
        {"Classic", 2018},
        {"Pejo", 2013},
        {"Siesta", 2014},
        {"Fusca", 1995},
        {"Siena", 2007},
    };

    int tam = sizeof(veiculos)/sizeof(Veiculo);

    printf("Array nao ordenado\n");
    for(int i = 0; i < tam;i++){
        printf("nome: %s ano: %i\n", veiculos[i].nome, veiculos[i].ano);
    }

    radix_sort(veiculos, tam);

    printf("Array ordenado\n");
    for(int i = 0; i < tam;i++){
        printf("nome: %s ano: %i\n", veiculos[i].nome, veiculos[i].ano);
    }

    return 0;
}

int maior(Veiculo *a, int tam){
    int maior = a[0].ano;
    for(int i = 0; i < tam; i++){
        if(a[i].ano > maior){
            maior = a[i].ano;
        }
    }
    return maior;
}

void counting_sort(Veiculo *a, int tam, int pos){
    Veiculo aux[tam];
    int count[10], i, digito;

    for(i = 0; i < 10; i++){
        count[i] = 0;
    }
    for(i = 0; i < tam; i++){
        digito = (a[i].ano/pos)%10;
        count[digito]++;
    }
    for(i = 1; i < 10; i++){
        count[i] += count[i-1];
    }
    for(i = tam-1; i >= 0; i--){
        digito = (a[i].ano/pos)%10;
        count[digito]--;
        aux[count[digito]] = a[i];
    }
    for(i = 0; i < tam; i++){
        a[i] = aux[i];
    }
}

void radix_sort(Veiculo *a, int tam){
    int max = maior(a, tam);
    for(int pos = 1; max/pos > 0; pos*=10){
        counting_sort(a, tam, pos);
    }
}