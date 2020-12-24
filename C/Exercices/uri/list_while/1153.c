#include <stdio.h>

int main(){
    int n, fat = 1,c;

    scanf("%d", &n);
    c = n;
    while(c > 1){
        fat = fat * c;
        c--;
    }

    printf("%i\n", fat);
    
    return 0;
}