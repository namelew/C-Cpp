#include <stdio.h>
int main()
{
    int array[3], i, ord[3], j, temp;
    for(i = 0; i < 3; i++){
        scanf("%d", &array[i]);
    }

    for(i = 0; i < 3; i++){
        ord[i] = array[i];
    }

    for(i = 0; i < 3; i++){
        for(j = i + 1; j < 3; j++){
            if(ord[i] > ord[j]){
                temp = ord[i];
                ord[i] = ord[j];
                ord[j] = temp;
            }
        }
    }

    for(i = 0; i < 3; i++){
        printf("%i\n", ord[i]);
    }
    printf("\n");

    for(i = 0; i < 3; i++){
        printf("%i\n", array[i]);
    }
    return 0;
}