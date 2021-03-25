#include <stdio.h>

void fibonacci(int pos,int current, int next);

int main(void){
	int pos;
	printf("Fibonnaci's position: ");
	scanf("%d", &pos);
	fibonacci(pos, 0, 1);
	return 0;
}

void fibonacci(int pos,int current, int next){
	if(pos>-1){
		printf("%i -> ", current);
		fibonacci(--pos,current+next, current);
	} else{
		printf("Fim\n");
	}
}