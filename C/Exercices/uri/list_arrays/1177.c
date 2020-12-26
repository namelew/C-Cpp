// Minha solução
# include <stdio.h>

int main(){
    int array[1000] = {0}, n, c=0, i;

    scanf("%d", &n);

    do{
        for(i = 0; i < n; i++){
            array[c] = i;
            c++;
        }
        if(c == 999){
            break;
        }
    }while(array[c] == 0);

    for(c = 0; c < 1000; c++){
        printf("N[%i] = %i\n", c, array[c]);
    }

    return 0;
}
/*
Solção que o uri aceitou
#include <stdio.h>
int main()
{
    int n[1000], x, y,a;
    scanf ("%d", &x);
    for(y=0,a=0; y<1000; y++)
    {
        printf("N[%d] = %d\n",y,a);
        a++;
        if(a==x)
            a=0;
    }
    return 0;
}
*/