# include <stdio.h>

int main(){
    int c=1;
    while(c <= 100){
        if (c%2 == 0){
            printf("%i\n", c);
        }
        c++;
    }
    return 0;
}