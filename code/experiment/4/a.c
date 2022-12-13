#include <stdio.h>

int a[100000];

void check(int x)
{
    int a,b,c;
    a = x / 100 % 10;
    b = x / 10 % 10;
    c = x % 10;
    if(a * a * a + b * b * b + c * c * c == x)
        printf("%d\n",x);
}


int main()
{
    for(int i = 100;i < 1000;i++)
        check(i);
    return 0;
}
    
