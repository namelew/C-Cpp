# include <iostream>

// in c++, you can create two functions with the same name if they parameters be diferent between each other.

using namespace std;

int sum(int a, int b);
void sum();

int main(){
    cout << sum(17, 15) << '\n';
    sum();

    return 0;
}

int sum(int a, int b){
    return a + b;
}

void sum(){
    cout << 3 + 2 << '\n';
}
