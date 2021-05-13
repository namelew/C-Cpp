#include <stdio.h>
#include <math.h>



double PontoMin(double X, double Y){

    double A,B,C,R1,R2,F;

    
    //Isolamos D e chegamos em: 10000X^2+11600Y^2+D(-200Y^2+200X^2)+D^2(Y^2-X^2)=0 , é necessário realizar o tratamento para quadrática

    // a= (Y^2-X^2)   b = (-200Y^2+200X^2)  c = 10000X^2+11600Y^2

    A= pow(Y,2)-pow(X,2);

    B= (-200*pow(Y,2))+(200*pow(X,2));

    C= (-10000*pow(X,2))+(11600*pow(Y,2));

    R1= (-B+sqrt((pow(B,2)-4*A*C)))/(2*A);
    printf("R1:%lf\n",R1);

    R2= (-B-sqrt((pow(B,2)-4*A*C)))/(2*A);
    printf("R2:%lf\n",R2);

    if (R1<R2)
    {
        F=R1;
        printf("%lf\n",F);

    }else{

        F=R2;
        printf("%lf",F);
    }

    if (F<0)
    {
        F=-1*F;
    }

    return F;

}



int main(){

    double X=0,Y=0,D,DT;

    while (X<=Y)
    {
       printf("Informe a velocidade do carro: "); 
       scanf("%lf",&X);

       printf("informe a velocidade do barco: ");
       scanf("%lf",&Y);
    }
    

    D=PontoMin(X,Y);

    DT=(D+(sqrt((40*40)+((100-D)*(100-D)))));

    printf("Distancia Cidade - Estacao = %lf\n",D);

    printf("Distancia barco: %lf\n",(sqrt((40*40)+((100-D)*(100-D)))));

    printf("Distancia Total = %lf",DT);
    return;
    
}