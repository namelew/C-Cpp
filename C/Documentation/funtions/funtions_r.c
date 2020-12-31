# include <stdio.h>

int main(void){
    int resul, n;
    int fatorial(int num);

    printf("Digite um valor: ");
    scanf("%d", &n);

    resul = fatorial(n);

    printf("O fatorial de %i eh %i\n", n, resul);

    system("pause");
    return 0;
}
int fatorial(int num){
    if(num == 0) return 1;
    else return num * fatorial(num-1);
}
