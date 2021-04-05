#include <iostream>

using namespace std;

int main(){
    
    int below_limit, upper_limit;
    
    cin >> below_limit; // recebendo valores
    cin >> upper_limit; 
    
    int temp = 1; // utilizando uma variavel de controle em vez de usar x
    
    for(int i = 1; i <= upper_limit; i++){
            if(temp == below_limit) {
                 cout << i << "\n";
                 temp = 1; // resetando o n apenas se a condição eh verdadeira
            }
            else{
                cout << i << " ";
                temp++; // incrementando se for falsa
            }
    }
    return 0;
}