# include <iostream>
# include <stdio.h>

using namespace std;

typedef struct{
    double nota1;
    double nota2;
    double media;
}Status;

int main(){
    Status aluno;
    int op=0;

    do{
        cin >> aluno.nota1;
        while(aluno.nota1>10 || aluno.nota1 < 0){
            cout << "nota invalida\n";
            cin >> aluno.nota1;
        }
        cin >> aluno.nota2;
        while(aluno.nota2>10 || aluno.nota2<0){
            cout << "nota invalida\n";
            cin >> aluno.nota2;
        }
        aluno.media = (aluno.nota1 + aluno.nota2)/2;
        printf("media = %.2lf\n", aluno.media);
        cout << "novo calculo (1-sim 2-nao)\n";
        cin >> op;
        while(op != 1 && op != 2){
            cout << "novo calculo (1-sim 2-nao)\n";
            cin >> op;
        }
    }while(op != 2);

    return 0;
}