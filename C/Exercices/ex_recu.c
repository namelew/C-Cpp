# include <stdio.h>
# include <string.h>


void reverse(char *string, int n);

int main(){
	char *palavra = "Amordeser";
	char binare[256];
	reverse(palavra, 0);
	printf("\n");
	bin(23, binare, 0);
	printf("%s\n", binare);
	return 0;
}

void reverse(char *string, int n){
	if(string[n] == '\0'){return;}
	reverse(string, n+1);
	printf("%c", string[n]);
}

void bin(int i, char *string, int pos){
	int resto, valor;
	if(i < 2){
		string[pos] = i+48;
		return;
	}
	resto = i%2;
	valor = i/2;
	bin(valor, string, i+1);
	string[pos] = resto?'1':'0';	
}