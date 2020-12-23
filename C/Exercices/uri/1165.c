# include <stdio.h>

int main(){
    int num, c, ehprimo = 1, n, cout;

    scanf("%d", &n);

    for(cout = 0; cout < n; cout++)
    {
        scanf("%d", &num);

        if(num == 1){
            ehprimo = 0;
        } else{
            ehprimo = 1;
        }

        for (c = 2; c < num; c++){
            if(num%c == 0) {ehprimo = 0;}
        }
        
        if(ehprimo == 1){printf("%i eh primo\n", num);} 
        else{printf("%i nao eh primo\n", num);}
    }
    return 0;
}
