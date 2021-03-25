#include<stdio.h>

typedef struct{
     double real;
     double imaginario;
}Complexo;

Complexo criaComplexo(double real, double imaginario);
Complexo somaComplexo(Complexo a, Complexo b);

int main(){
	Complexo n1, n2, sum;
	scanf("%lf %lf", &n1.real, &n1.imaginario);
	scanf("%lf %lf", &n2.real, &n2.imaginario);

	sum = somaComplexo(n1, n2);

	printf("Soma dos Reais = %.2lf\nSoma dos Imaginarios = %.2lf\n", sum.real, sum.imaginario);

    return 0;
}

Complexo criaComplexo(double real, double imaginario){
	Complexo com = {real, imaginario};
	return com;
}

Complexo somaComplexo(Complexo a, Complexo b){
	Complexo soma;
	soma.imaginario = a.imaginario + b.imaginario;
	soma.real = a.real + b.real;
	return soma;
}
