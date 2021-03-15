# include <iostream>

using namespace std;

void print_t(string txt = "Standard Paramenter");

int main(){

    print_t(); // if the function had a std arg, the paramanter pass can be omitted

    print_t("New argument");

    return 0;
}

void print_t(string txt){
    cout << txt << '\n';
}