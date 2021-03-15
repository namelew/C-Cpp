# include <iostream>

using namespace std;

int fatorial(int n);

int main(){
    cout << fatorial(5) << '\n';
    return 0;
}

int fatorial(int n){
    if(n == 0){
        return 1;
    }
    return n * fatorial(n-1);
}