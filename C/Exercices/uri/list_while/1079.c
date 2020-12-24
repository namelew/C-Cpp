# include <stdio.h>

int main(){
    int c = 1, n;
    double media, n1, n2, n3;

    scanf("%d", &n);

    while (c <= n){
        scanf("%lf %lf %lf", &n1, &n2, &n3);
        media = ((n1 * 2) + (n2 * 3) + (n3 * 5))/10;
        printf("%.1lf\n", media);
        c++;
    }
    
    return 0;
}