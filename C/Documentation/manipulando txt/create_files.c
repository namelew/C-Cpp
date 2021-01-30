# include <stdio.h>

int main(void){

    FILE *file;

    file = fopen("teste.txt", "w");
    fprintf(file,"Sono.");
    fclose(file);


    return 0;
}