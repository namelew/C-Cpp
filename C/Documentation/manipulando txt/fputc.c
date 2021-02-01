# include <stdio.h>

int main(void){
    char x[] = "coxinha";
    int i = 0;
    // fgutc e putc são o mesmo caso de getc e fgetc
    // stdout é apreviação de standart output
    FILE *file = fopen("teste.txt", "a");
    while(x[i] != '\0'){
        fputc(x[i], stdout);
        ++i;
    }
    //fputc('a', file);

    fclose(file);

    return 0;
}