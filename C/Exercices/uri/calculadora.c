# include <stdio.h>
# include <math.h>

int main(){
    int o;
    double a, b, soma, multi, div, pot, raiz, sub;

    printf("Digite dois numeros: ");
    scanf("%lf %lf", &a, &b);

    do{
        printf("Escolha uma opcao:\n");
        printf("0 - Sair\n");
        printf("1 - Somar\n");
        printf("2 - Subtrair\n");
        printf("3 - Mutiplicar\n");
        printf("4 - Dividir\n");
        printf("5 - Potencia de A por 2\n");
        printf("6 - Raiz de B\n");
        printf("7 - Alterar os numeros\n");
        scanf("%d", &o);
        
        switch (o){
            case 0:
                break;
            case 1:
                soma = a + b;
                printf("%.2lf + %.2lf = %.2lf\n", a, b, soma);
                break;
            case 2:
                sub = a - b;
                printf("%.2lf - %.2lf = %.2lf\n", a, b, sub);
                break;
            case 3:
                multi = a * b;
                printf("%.2lf * %.2lf = %.2lf\n", a, b, multi);
                break;
            case 4:
                div = a/b;
                printf("%.2lf / %.2lf = %.2lf\n", a, b, div);
                break;
            case 5:
                pot = pow(a, 2);
                printf("%.2lf ** 2 = %.2lf\n", a, pot);
                break;
            case 6:
                raiz = sqrt(b);
                printf("%.2lf ** 1/2 = %.2lf\n", b, raiz);
                break;
            case 7:
                printf("Novos valores para A e B: ");
                scanf("%lf %lf", &a, &b);
                break;
            default:
                printf("Opçao Invalida!\n");
        }
    } while(o != 0);


    return 0;
}