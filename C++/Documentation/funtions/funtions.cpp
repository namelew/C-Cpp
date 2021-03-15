# include <iostream>
# include <stdlib.h>

using namespace std;

int sum(int a, int b);
void printv(float array[], int tam);

int main(){
    int n1 = 2, n2 = 4;
    float trans[5] = {2.1, 3.4, 4.5, 5.6, 6.7};

    printv(trans,(int) sizeof(trans)/sizeof(float));

    cout << sum(n1, n2) <<'\n';

    return 0;
}

int sum(int a, int b){
    return a + b;
}

void printv(float array[], int tam){
    int i;

    for(i = 0; i < tam; i++){
        cout << array[i] << '\n';
    }
    
}
