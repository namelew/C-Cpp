#include <stdio.h>

int main(){
    int n, fat = 1,c;

    scanf("%d", &n);

    for(c = n; c > 1; c--){
        fat = fat * c;
    }

    printf("%i\n", fat);
    
    return 0;
}