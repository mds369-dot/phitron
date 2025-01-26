#include<stdio.h>
int main()
{
    long long int a;
    scanf("%lld", &a);
    long long int x = (a * (a + 1))/2;
    printf("%lld",x);
    return 0;
}