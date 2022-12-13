#include <stdio.h>

int main()
{
    int max(int x,int y);
    int a,b,c;
    scanf("%d,%d",&a,&b);
    c = max(a,b);
    printf("%d\n",c);
}

int max(int x,int y)
{
    int z;
    z = x > y? x:y;
    return z;
}
