# include <stdio.h>

int main(){
    int c;
    for(c = 1; c <= 100; c++){
        if (c%2 == 0){
            printf("%i\n", c);
        }
    }
    return 0;
}