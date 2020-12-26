#include <stdio.h>
int main()
{
   int array[20], temp,i,j;
    for(i=0; i<20; i++)
        scanf("%d",&array[i]);
    for(i=0, j=19; i<10; i++, j--)
    {
        temp=array[i];
        array[i]=array[j];
        array[j]=temp;
        
    }
    for(i=0; i<20; i++)
        printf("N[%d] = %d\n",i,array[i]);
    return 0;
}
