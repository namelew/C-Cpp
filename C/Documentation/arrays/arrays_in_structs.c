# include <stdio.h>

int main(void){
    int i;
    struct horario{
        int horas;
        int minutos;
        int segundos;
    } agora = {3}; // uma outra forma de declaração, já declarando um objeto e definindo valores para ele

    // nesse caso, cada espaço do vetor, é um objeto de horario
    struct horario teste[5]= {{10, 20, 30}, {6, 15, 40}, {12, 1, 45}, {13, 20, 30}, {14, 35, 30}}; // inserindo valores em cada um dos objetos

    for(i=0; i<5;i++){
        printf("%i:%i:%i\n", teste[i].horas, teste[i].minutos, teste[i].segundos);
    }

    return 0;
}