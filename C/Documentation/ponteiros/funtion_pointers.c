# include <stdio.h>

struct lista{
    int valor;
    struct list *proximo;
};

int main(void){
    struct lista *find_valor(struct lista *pLista, int valor);

    struct lista m1, m2, m3;
    struct lista *resultado, *gancho = &m1;
    int valor;

    m1.valor = 5;
    m2.valor = 10;
    m3.valor = 15;

    m1.proximo = &m2;
    m2.proximo = &m3;
    m3.proximo = 0;

    printf("Digite valor para pesquisa: ");
    scanf("%i", &valor);

    resultado = find_valor(gancho, valor);

    if (resultado == (struct lista *)0){
        printf("Valor nao encontrado\n");
    } else {
        printf("O valor %i foi encontrado\n", resultado -> valor);
    }

    return 0;
}

struct lista *find_valor(struct lista *pLista, int valor){
    while (pLista != (struct lista *)0){
        if (pLista -> valor == valor){
            return pLista;
        } else{
            pLista = pLista -> proximo;
        }
    }
    return (struct lista *)0;

}