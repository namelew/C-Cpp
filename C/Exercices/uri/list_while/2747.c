#include <stdio.h>
int main()
{
    int i=0,j=0;
    // j = linhas, i = espaços
    while(i<39)
       {
           printf("-");
           i++;
        }
        printf("\n");

        while(j<11)
        {
            i=0;
            while(i<39)
            {
                if(i==0&&(j%2==1)) printf("|");
                else if(i==38&&j%2==1) printf("|\n");
                else if(j%2==1)printf(" ");
                i++;
            }
            j++;
        }
        i = 0;
        while(i<39)
        {
            printf("-");
            i++;
        }
       printf("\n");

    return 0;
    
}