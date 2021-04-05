#include <iostream>

using namespace std;

int main(){
    int n=0, i;
    while(true){
        cin >> n;
        if(n==0){break;}
        for(i = 1; i <= n; i++){
            cout << i;
            cout << ((i == n)?"\n": " ");
        }
    }

    return 0;
}