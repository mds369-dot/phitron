#include<stdio.h>
int main()
{
    //div = dividend, re = remainder, qu = quotient, di = divisor
    int div, re, qu;
    scanf("%d %d %d",&div, &qu, &re);
    int di = (div - re)/qu;
    printf("%d", di);
    return 0;
}