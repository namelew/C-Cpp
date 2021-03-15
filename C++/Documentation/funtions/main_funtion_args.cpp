# include <iostream>
#include <string.h>

using namespace std;
//argc:store the number of parameters how will be pass
//argv: is a pointer how store the adress of the parameters pass
int main(int argc, char *argv[]){
    //cout << argv[0] << '\n'; the fist parameter is always the name of the file
    //cout << argv[1] << '\n'; acessing the next pamaeter
    if(argc > 1){
        if(!strcmp(argv[1], "sol")){
            cout << "Deu bom\n";
        } else if(!strcmp(argv[1],"nublado")){
            cout << "Deu ruim\n";
        }else {
            cout << "Melhor fica em casa mesmo\n";
        }
    } else {
        cout << "No paramenter informed\n";
    }

    return 0;
}