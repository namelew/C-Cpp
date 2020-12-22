# include <stdio.h>

int main(){
    int n, pri, seng, ter, c;

    scanf("%d", &n);

    pri = 0;
    seng = 1;

    printf("%i %i ", pri, seng);

    for(c=2; c < n; c++){
        ter = pri + seng;

        if(c == n-1){
            printf("%i\n", ter);
        } else{
            printf("%i ", ter);
        }
        
        pri = seng;
        seng = ter;
    }

    return 0;
}