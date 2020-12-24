#include <stdio.h>

int main(){
    int n, par=0, c;
    for (c = 0; c < 5; c++){
        scanf("%d\n",&n);
        if(n%2 == 0){
            par++;
        }
    }
    printf("%i valores pares\n", par);
    
    return 0;
}