# include <stdio.h>
// O programa deve possui uma função que recebe os valores e uma que os printa na tela
// também deve possuir uma struct que armazena os dados
struct horario{
    int hora, minuto, segundo;
};

int main(void){
    void recebeH(struct horario array[5]);
    void printH(struct horario array[5]);

    struct horario horarios[5];

    recebeH(horarios);
    printf("\n");
    printH(horarios);

    return 0;
}

void recebeH(struct horario array[5]){
    int i;
    for(i = 0; i < 5; i++){
        scanf("%d:%d:%d", &array[i].hora, &array[i].minuto, &array[i].segundo);
    }

}
void printH(struct horario array[5]){
    int i;
    for(i = 0; i < 5; i++){
        printf("%2d:%2d:%2d\n", array[i].hora, array[i].minuto, array[i].segundo);
    }
}