# include <stdio.h>

int main(void){
    struct horario{int hora, minuto, segundo;};
    // variável de uma estrutura de tipo horario
    struct horario agora;
    // ponterio para uma estrutura de tipo horario
    struct horario *depois;
    depois = &agora;
    // modificando os valores de agora pelo ponteiro
    depois -> hora = 10;
    // outra forma é utilizado o formato (*ponteiro).atributo = valor;
    // mas essa foram é a mais utilizando pelos programadores
    depois -> minuto = 20;
    depois -> segundo = 30;

    printf("%i:%i:%i", agora.hora, agora.minuto, agora.segundo);

    return 0;
}