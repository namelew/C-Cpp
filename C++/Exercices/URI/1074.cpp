#include <iostream>

using namespace std;

int main(){
    int q, i;

    cin >> q;

    int array[q];

    for(i = 0; i < q; i++){
        cin >> array[i];
    }
    for(i = 0; i < q; i++){
        if(array[i] == 0){
            cout << "NULL\n";
        }else{
            if(array[i]%2 == 0){
                cout << "EVEN";
                if(array[i] > 0){
                    cout<<" POSITIVE";
                } else {
                    cout<<" NEGATIVE";
                }
                cout << "\n";
            }else{
                cout << "ODD";
                if(array[i] > 0){
                    cout<<" POSITIVE";
                } else {
                    cout<<" NEGATIVE";
                }
                cout << "\n";
            }
        }
    }

    return 0;
}