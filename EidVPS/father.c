#include<stdio.h>
int main()
{
    int total_age;
    scanf("%d", &total_age);
    int daughter_age = total_age/5;
    int father_age = total_age - daughter_age;
    printf("%d %d",father_age,daughter_age);
    return 0;
}