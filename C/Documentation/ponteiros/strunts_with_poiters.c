#include <stdio.h>
// utilizando ponterios dentro de estruturas
int main(void){
    struct horario{
        int *pHora, *pMinuto, *pSegundo;
    };
    struct horario hoje;

    int hora = 20, minuto = 30, segundos = 40;

    hoje.pHora = &hora;
    hoje.pMinuto = &minuto;
    hoje.pSegundo = &segundos;

    printf("Hora: %i\n", *hoje.pHora);
    printf("Minuto: %i\n", *hoje.pMinuto);
    printf("Segundo: %i\n", *hoje.pSegundo);

    *hoje.pSegundo = 20;
    printf("Segundo: %i\n", segundos);

    return 0;
}