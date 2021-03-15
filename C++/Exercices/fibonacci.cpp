#include <iostream>

using namespace std;

void fibonacci(int posi,int current=0, int next=1);

int main()
{
    int pos;
    cout << "Fibonacci's position: ";
    cin >> pos;
    fibonacci(pos);
    return 0;
}

void fibonacci(int posi, int current, int next){
    if(posi>0){
        cout << current << " -> ";
        fibonacci(--posi,current+next,current);
    }else{
        cout << "Fim\n";
    }
}