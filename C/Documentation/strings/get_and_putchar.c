# include <stdio.h>

int main(void){
    char x;

    // getchar
    while((x=getchar()) != "\n"){
        // putchar
        putchar(x);
    }
    
    return 0;
}