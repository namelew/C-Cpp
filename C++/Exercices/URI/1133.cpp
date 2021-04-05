# include <iostream>

using namespace std;

int main(){
    int a, b;
    
    cin >> a;
    cin >> b;

    if(a > b){
        b++;
        while (b < a){
            if(b%5 == 2 || b%5 == 3){
                cout << b << '\n';
            }
            b++;
        }
    } else if(b > a){
        a++;
        while (a < b){
            if(a%5 == 2 || a%5 == 3){
                cout << a << '\n';
            }
            a++;
        }
    }

    return 0;
}