# include <stdio.h>
// variáveis "auto" são desalocadas automaticamente depois do fim da função
// variáveis "extern" são declaradas pelo compilador, mas não tem memória alocada
int main(void){
    auto int var; // var deixará de existir ao fim de main
    // nesse caso em específico auto int var; == int var;
    extern int other; // apenas declaração sem a alocação de memória
    // ela é utilizada para reutilizar uma variável já declarada em outro arquivo .h ou .c
    // caso o linked, não encontre a variável other em outro código dentro da mesma pasta, haverá um erro de compilação pois não existe um espaço da memoria alocado para ele.
    return 0;
}