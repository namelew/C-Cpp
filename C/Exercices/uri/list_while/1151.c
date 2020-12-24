# include <stdio.h>

int main(){
    int n, pri, seng, ter, c=2;

    scanf("%d", &n);

    pri = 0;
    seng = 1;

    printf("%i %i ", pri, seng);

    while (c < n){
        ter = pri + seng;

        if(c == n-1){
            printf("%i\n", ter);
        } else{
            printf("%i ", ter);
        }
        
        pri = seng;
        seng = ter;
        c++;
    }

    return 0;
}