# include <iostream>

using namespace std;

int main(){
    double n1, n2, media;

    cout << "Nota 1: ";
    cin >> n1;
    cout << "Nota 2: ";
    cin >> n2;

    media = (n1 + n2)/2;

    if(media > 7){
        cout << "Aluno Aprovado. Media: " << media << "\n";  
    } else if(media > 5.5 && media < 7){
        cout << "Aluno em recuperacao. Media: " << media <<"\n";
    } else{
        cout << "Aluno reprovado por nota. Media: " << media <<"\n";
    }
    
    return 0;
}