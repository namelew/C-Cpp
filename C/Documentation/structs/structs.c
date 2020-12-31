# include <stdio.h>
/* Estruturas(structs) são locais, parecidas com vetores, que podem armazenar e
correlacionar vários valores. A sua difereça para os vetores é que elas podem re_
ceber valores de tipos diferentes.
*/
int main(void){
    // definindo uma struct
    struct horario{
        int horas, minutos, segundos;
        char letras;
        double teste;
    };
    // declarando a struct
    //    tipo      nome
    struct horario agora;
    // alterando valores
    agora.horas = 13;
    agora.minutos = 46;
    agora.segundos = 30;

    // trabalhando com valores
    struct horario depois;
    
    depois.horas = agora.horas + 2;
    depois.minutos = agora.minutos;
    depois.teste = 57.5/agora.segundos;
    depois.letras = 'c';

    printf("%i\n", depois.horas);
    printf("%i\n", depois.minutos);
    printf("%lf\n", depois.teste);
    printf("%c\n", depois.letras);

    return 0;
}