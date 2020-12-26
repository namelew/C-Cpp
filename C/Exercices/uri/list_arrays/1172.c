# include <stdio.h>

int main(){
    int array[10];

    for(int c = 0; c < 10; c++){
        scanf("%d", &array[c]);
        if(array[c] <= 0){array[c] = 1;}
    }
    for(int c = 0; c < 10; c++){
        printf("X[%i] = %i\n", c, array[c]);
    }

    return 0;
}