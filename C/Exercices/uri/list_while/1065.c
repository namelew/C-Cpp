#include <stdio.h>

int main(){
    int n, par=0, c=0;
    while (c < 5){
        scanf("%d\n",&n);
        if(n%2 == 0){
            par++;
        }
        c++;
    }
    printf("%i valores pares\n", par);
    
    return 0;
}