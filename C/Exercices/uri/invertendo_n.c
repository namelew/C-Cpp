# include <stdio.h>

int main(){
    int n, cifra;

    scanf("%d", &n);

    if(n >= 0){
        do{
            cifra = n % 10;
            printf("%i", cifra);
            n/= 10;
        } while(n != 0);
        printf("\n");
    } else if ( n < 1){
        n = n * -1;
        printf("-");
        do{
            cifra = n % 10;
            printf("%i", cifra);
            n/= 10;
        } while(n != 0);
        printf("\n");
    }
    return 0;
}