#include <stdio.h>
#include <stdlib.h>

int main(void){
	void maior_e_menor(int array[], int tam);
	int array[5] = {1, 7, 3, 2, 9};

	maior_e_menor(array, 5);

	return 0;
}

void maior_e_menor(int array[], int tam){
	int maior, menor, i;

	for(i = 0; i < tam; i++){
		if(i == 0 || array[i] > maior){maior = array[i];}
		if(i == 0 || array[i] < menor){menor = array[i];}
	}
    
	printf("Maior: %i\nMenor: %i\n", maior, menor);
}
