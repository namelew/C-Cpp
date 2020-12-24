# include <stdio.h>

int main(){
    int n100, n50, n20, n10, n5, n2, n1, num, cop;

    scanf("%i", &num);
    cop = num;
    for(n100 = 0; num >= 100; n100++){
        num = num - 100;
    }
    for (n50 = 0; num >= 50; n50++)
    {
        num = num - 50;
    }
    for(n20 = 0; num >= 20; n20++){
        num = num - 20;
    }
    for(n10 = 0; num >= 10; n10++){
        num = num - 10;
    }
    for(n5 = 0; num >= 5; n5++){
        num = num - 5;
    }
    for(n2 = 0; num >= 2; n2++){
        num = num - 2;
    }
    for(n1 = 0; num >= 1; n1++){
        num = num - 1;
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