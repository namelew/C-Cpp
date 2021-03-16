#include <stdio.h>

struct data{
	int dia, mes, ano;
};

int extrai_data(struct data d){
	return d.dia;
}

int compara_data(struct data d1, struct data d2){
	int dif = (d1.ano+d1.mes+d1.dia) - (d2.ano + d2.mes + d2.dia);
	if(dif > 0){
		return 1;
	} else if(dif < 0){
		return -1;
	}
	return 0;
}

int main(void){
	struct data d1, d2;
	int res;

	scanf("%d/%d/%d", &d1.dia, &d1.mes, &d1.ano);
	scanf("%d/%d/%d", &d2.dia, &d2.mes, &d2.ano);
	
	printf("%i\n", extrai_data(d1));
	
	res = compara_data(d1,d2);

	if(res == 1){
		printf("A data 1 eh posterior a data 2\n");
	} 
	if(res == -1){
		printf("A data 1 eh anterior a data 2\n");
	} 
	if(res == 0) {
		printf("Ambas sao iguias\n");
	}
	
	return 0;
}
