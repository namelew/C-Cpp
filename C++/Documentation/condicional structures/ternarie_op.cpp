#include <iostream>

using namespace std;

int main(){
    int n1, n2, media;
    string res;

    cout << "Nota 1: ";
    cin >> n1;
    cout << "Nota 2: ";
    cin >> n2;

    media = (n1 + n2)/2;

    (media >= 6) ? res="Aprovado\n": res= "Reprovado\n";

    cout << "Situacao do Aluno: "<< res;
    
    return 0;
}