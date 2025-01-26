#include<stdio.h>
int main()
{
    int daily_income;
    scanf("%d",&daily_income);
    long long int yearly_income = (long long int)daily_income * 365;
    printf("%lld", yearly_income);
    return 0;
}