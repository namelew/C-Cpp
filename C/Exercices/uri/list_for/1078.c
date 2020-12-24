#include <stdio.h>

int main(){
    int n, c, multi;

    scanf("%i", &n);

    for (c=1; c <= 10; c++){
        multi = c * n;
        printf("%i x %i = %i\n", c, n, multi);
    }

    return 0;
}