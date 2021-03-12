# include <iostream>

using namespace std;

int main(){
    int i,j, matriz[2][2] = {{1, 2},{3, 4}};

    for(i = 0; i<2; i++){
        for(j=0; j<2; j++){
            cout << matriz[i][j] << "\n";
        }
    }

    return 0;
}
