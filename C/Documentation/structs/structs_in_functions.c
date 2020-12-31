# include <stdio.h>
// Sempre que for utilizar uma função struct como parâmetro de uma função
// A struct terá que ser declarada como global
struct horario{
        int horas, minutos, segundos;
};

int main(void){
    struct horario teste(struct horario x);

    struct horario agora;

    agora.horas = 10;
    agora.minutos = 42;
    agora.segundos = 58;

    struct horario proxima;
    proxima = teste(agora); // ao retornar uma struct, seus valores devem ser armazenados em outra struct de mesmo tipo

    printf("%i:%i:%i\n", proxima.horas, proxima.minutos, proxima.segundos);

    return 0;
}

struct horario teste(struct horario x){
    printf("%i:%i:%i\n", x.horas, x.minutos, x.segundos);

    x.horas = 24;
    x.minutos = 60;
    x.segundos = 60;

    return x;
}