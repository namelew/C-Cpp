# include <stdio.h>

// Funções para limpeza de buffer
// setbuf(FILE *, NULL); - só funciona em windows(aparentemente)
// fflush(stdout); - só funciona pra output
// clear_b() - função criada

int main(void){
    void clear_b(void);
    char a,b,c;

    a = getchar();
    clear_b();
    b = getchar();
    clear_b();
    c = getchar();
    clear_b();

    printf("%c", a);
    printf("%c", b);
    printf("%c", c);

    return 0;
}

void clear_b(void){
    char c;
    while((c=getchar()) != '\n' && c != EOF);
}