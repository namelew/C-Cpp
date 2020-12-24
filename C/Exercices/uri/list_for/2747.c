#include <stdio.h>
int main()
{
    int i,j;
    // j = linhas, i = espaços
    for(i=0;i<39;i++)
       {
           printf("-");
        }
        printf("\n");

        for(j=0;j<11;j++)
        {
            for(i=0;i<39;i++)
            {
                if(i==0&&(j%2==1)) printf("|");
                else if(i==38&&j%2==1) printf("|\n");
                else if(j%2==1)printf(" ");
            }
        }

        for(i=0;i<39;i++)
        {
            printf("-");
        }
       printf("\n");

    return 0;
    
}