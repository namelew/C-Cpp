# include <iostream>

using namespace std;

int main(){
    int array[10], i, valor;

    cout<< "Digite um valor interio: ";
    cin >> valor;

    for(i = 0; i < 10; i++){
        array[i] = valor;
        valor*=2;
    }

    for(i=0;i<10;i++){
        cout<<array[i]<<"\n";
    }
    
    return 0;
}