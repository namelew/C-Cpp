# include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int m=1, n=1, sum, i=1;

    while(i==1){
        scanf("%i %i", &m, &n);
        sum = 0;
        if(m <= 0 || n <= 0){break;}
        if(m > n){
            while(n <= m){
                cout << n <<" ";
                sum += n;
                n++;
            }
            printf("Sum=%i\n",sum);
        }else if(n > m){
            while(m <= n){
                cout << m <<" ";
                sum += m;
                m++;
            }
            printf("Sum=%i\n",sum);
        } else{
            sum = m;
            printf("%i Sum=%i\n", m, sum);
        }
    }

    return 0;
}