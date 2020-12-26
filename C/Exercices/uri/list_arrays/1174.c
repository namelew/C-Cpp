# include <stdio.h>

int main(){
    float array[100] = {0};
    int c;

    for (c = 0; c < 100; c++){
        scanf("%f", &array[c]);
    }
    for (c = 0; c < 100; c++){
        if(array[c] <= 10.0){printf("A[%i] = %.1f\n", c, array[c]);}
    }

    return 0;
}