#include<stdio.h>
int main()
{
    int total_taka, less_taka;
    scanf("%d %d",&total_taka, &less_taka);
    int rina = (total_taka - less_taka) / 2;
    int mina = rina + less_taka;
    printf("%d %d", mina, rina);
    return 0;
}