#include<stdio.h>
int main()
{
    int a, i;
    scanf("%d", &a);
    int n = (a-12)/8;
    for (i = 0; i < 4; i++)
    {
        int odd = 2 *  n + 2 * i + 1;
        printf("%d ", odd);
    }
    
}