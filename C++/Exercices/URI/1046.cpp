#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int start, end;
    scanf("%d %d", &start, &end);

    if(start > end){
        printf("O JOGO DUROU %i HORA(S)\n", end + (24 - start));
    } else{
        printf("O JOGO DUROU %i HORA(S)\n", end - start);
    }

    return 0;
}