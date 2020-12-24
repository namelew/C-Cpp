# include <stdio.h>

int main(){
    int n1 = 20, n2 = 11, resp;
//  condição     ação(True)      ação(False)
    n1 > n2 ? (printf("Sim\n")): (printf("Nao\n"));

    n1 > n2 ? (resp = 10): (resp = -10);

    printf("%i", resp);

    return 0;
}