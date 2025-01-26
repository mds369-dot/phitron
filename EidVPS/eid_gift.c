#include<stdio.h>
int main()
{
    int gift, children;
    scanf("%d %d",&gift,&children);
    int n = gift / children;
    int a = gift % children;
    printf("%d %d", n, a);
    return 0;

}
 