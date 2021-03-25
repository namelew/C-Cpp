# include <iostream>
# include <stdio.h>

using namespace std;

int main(){
    int n, i, q, qs=0, qc=0, qr=0, qt=0;
    char t;
    double pc, pr,ps;

    cin >> n;

    for(i = 0; i < n; i++){
        scanf("%d %c", &q, &t);
        if(t == 'C'){qc= qc + q;}
        if(t == 'R'){qr= qr + q;}
        if(t == 'S'){qs+=q;}
        qt+=q;
    }

    cout<< "Total: "<< qt << " cobaias\n";
    cout<< "Total de coelhos: "<< qc << "\n";
    cout<< "Total de ratos: "<< qr << "\n";
    cout<< "Total de sapos: "<< qs << "\n";

    pc = (double)qc/qt;
    pr = (double)qr/qt;
    ps = (double)qs/qt;

    printf("Percentual de coelhos: %.2lf %%\n", pc*100.0);
    printf("Percentual de ratos: %.2lf %%\n", pr*100.0);
    printf("Percentual de sapos: %.2lf %%\n", ps*100.0);

    return 0;
}