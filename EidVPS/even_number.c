#include<stdio.h>
int main()
{
    int x, i;
    scanf("%d",&x);
    int n = (x-20)/10;
    for(i=0;i<5;i++)
    {
        printf("%d ",2 * (n+i));
    }
    
    return 0;
}