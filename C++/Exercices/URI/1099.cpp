# include <iostream>
# include <stdio.h>

using namespace std;

int main(){
    int n, i, a, b;

    cin >> n;

    int sum[n];

    for(i = 0; i < n; i++){
        scanf("%i %i", &a,&b);
        if(a > b){
            b++;
            sum[i] = 0;
            while(b < a){
                if(b%2 != 0){
                    sum[i] += b;
                }
                b++;
            }
        } else if (b > a){
            a++;
            sum[i] = 0;
            while(a < b){
                if(a%2 != 0){
                    sum[i] += a;
                }
                a++;
            }
        } else {sum[i] = 0;}
    }
    for(i = 0; i < n; i++){
        cout << sum[i] << "\n";
    }

    return 0;
}