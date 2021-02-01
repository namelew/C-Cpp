# include <stdio.h>
// stdin diz que o programa vai receber dados da entrada padrão, nesse caso o teclado
int main(void){
    char x[100];

    fgets(x, 100, stdin); // pega as coisas que foram digitas, transforma em string e guarda em x

    printf("%s\n", x);

    freopen("teste.txt", "r", stdin); //redireciona o ponteiro para o novo endereço de memória informado
    fgets(x, 100, stdin);
    printf("%s", x);

    return 0;
}