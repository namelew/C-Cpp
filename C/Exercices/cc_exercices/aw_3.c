# include <stdio.h>
# include <string.h>
# include <math.h>

#define TAM_F 100
#define EXIT 0
#define E 2.71828

typedef struct {
    double a;
    double b;
    int tam;
}Intervalo;

double f_fixo(double x){
    return pow(E, x) + 2;
}

void integral(Intervalo *i);

int main(){
    Intervalo i;
    int op=EXIT+1;
    while(op){
        printf("F(x) fixo = (e^x) + 2\n");
        printf("Intervalo(template: a b): ");
        scanf("%lf %lf", &i.a, &i.b);
        getchar();
        printf("Partes: ");
        scanf("%d", &i.tam);
        integral(&i);
        printf("Deseja calcular outra area?(S-1, N-0)\n:");
        scanf("%d", &op);
    }
    return 0;
}

void integral(Intervalo *i){
    int id = 0;
    double delta = (i->b-i->a)/i->tam, areat = 0;
    while(id < i->tam){
        areat += delta*f_fixo(i->a+(id*delta));
        id++;
    }
    printf("Area da figura: %.4lf\n", areat);
}