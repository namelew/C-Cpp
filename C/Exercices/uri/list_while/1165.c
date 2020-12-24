# include <stdio.h>

int main(){
    int num, c, ehprimo = 1, n, cout=0;

    scanf("%d", &n);

    while(cout < n)
    {
        scanf("%d", &num);

        if(num == 1){
            ehprimo = 0;
        } else{
            ehprimo = 1;
        }
        c = 2;
        while (c < num){

            if(num%c == 0) {ehprimo = 0;}
            c++;
        }
        
        if(ehprimo == 1){printf("%i eh primo\n", num);} 
        else{printf("%i nao eh primo\n", num);}

        cout++;
    }
    return 0;
}
