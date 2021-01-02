# include <stdio.h>

int main(void){
    // comandos de escape executam coisas ao final de uma string ou quando são chamados
    // São eles:
    // \n: move o cursor para a próxima linha, pula uma linha
    printf("De aluno para aluno\n");
    // \a: gera um som após printar a string
    printf("Sons do sistema\a\n");
    // \0: indica o fim de uma string
    printf("Fim\0 da string");
    // \b: move o cursor para a esquerda, ele não apaga apenas move
    printf("Palavra\b\n");
    // \t: habilita o uso do tab
    printf("Palavra\t");
    // \r: volta o curso para o início da linha
    printf("Palavra\r");
    // \" e \': indicam que '' ou "" são caractes e não sinais da linguagem.
    printf("\"Palvra\", \'palavra\'\n");


    //getchar();



    return 0;
}