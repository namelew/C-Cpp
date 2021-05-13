# include <stdio.h>
# include <math.h>

# define PI 3.14

typedef struct{
    double V,X,Y;
}Variables;

double raio(Variables f);
double altura(Variables f);
double area(Variables f);
double custoX(Variables f);
double custoY(Variables f);

int main(){
    Variables c;

    scanf("%lf %lf %lf", &c.V, &c.X, &c.Y);

    printf("Raio minizado: %.2lf m\n", raio(c));
    printf("Altura minizada: %.2lf m\n", altura(c));
    printf("Area total reduzida: %.2lf m^2\n", area(c));
    printf("Custo minimizado: R$ %.2lf\n", custoX(c) + custoY(c));

    return 0;
}

double raio(Variables f){
    return pow(f.V/2*PI, 1.0/3);
}

double altura(Variables f){
    return pow((4*f.V)/PI, 1.0/3);
}

double area(Variables f){
    return 2*PI*pow(raio(f), 2) + 2*PI*altura(f)*raio(f);
}

double custoX(Variables f){
    return f.X * (2 * PI * raio(f));
}

double custoY(Variables f){
    return f.Y * (2 * PI * raio(f) * altura(f));
}