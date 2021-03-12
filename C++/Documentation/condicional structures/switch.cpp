# include <iostream>

using namespace std;

int main(){
    int x, a, b, soma, sub, multi, div;

    cout << "A: ";
    cin >> a;
    cout << "B: ";
    cin >> b;
    cout << "1 - Soma A+B\n" << "2 - Sub A-B\n"<< "3- Multi A*B\n" << "4 Div A/b\n";
    cout << "Select one operation(Tip 0 to end): ";
    cin >> x;

    switch(x){
        case 1:
            soma = a + b;
            cout << "Soma: "<< soma << "\n";
            break;
        case 2:
            sub = a-b;
            cout << "Sub: "<< sub << "\n";
            break;
        case 3:
            multi = a*b;
            cout << "Multi: "<< multi << "\n";
            break;
        case 4:
            div = a/b;
            cout << "Div: "<< div<< "\n";
            break;
        default:
            cout << "Process ended! Have a nice day\n";
            break;
    }
    
    return 0;
}