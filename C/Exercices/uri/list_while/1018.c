# include <stdio.h>

int main(){
    int n100=0, n50=0, n20=0, n10=0, n5=0, n2=0, n1=0, num, cop;

    scanf("%i", &num);
    cop = num;
    while (num >= 100){
        num = num - 100;
        n100++;
    }
    while (num >= 50)
    {
        num = num - 50;
        n50++;
    }
    while(num >= 20){
        num = num - 20;
        n20++;
    }
    while(num >= 10){
        num = num - 10;
        n10++;
    }
    while(num >= 5){
        num = num - 5;
        n5++;
    }
    while(num >= 2){
        num = num - 2;
        n2++;
    }
    while(num >= 1){
        num = num - 1;
        n1++;
    }

    printf("%i\n", cop);
    printf("%i nota(s) de R$ 100,00\n", n100);
    printf("%i nota(s) de R$ 50,00\n", n50);
    printf("%i nota(s) de R$ 20,00\n", n20);
    printf("%i nota(s) de R$ 10,00\n", n10);
    printf("%i nota(s) de R$ 5,00\n", n5);
    printf("%i nota(s) de R$ 2,00\n", n2);
    printf("%i nota(s) de R$ 1,00\n", n1);

    return 0;
}