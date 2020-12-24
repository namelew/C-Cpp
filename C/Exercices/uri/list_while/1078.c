#include <stdio.h>

int main(){
    int n, c=1, multi;

    scanf("%i", &n);

    while (c <= 10){
        multi = c * n;
        printf("%i x %i = %i\n", c, n, multi);
        c++;
    }

    return 0;
}