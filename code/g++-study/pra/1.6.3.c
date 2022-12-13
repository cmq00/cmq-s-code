#include <stdio.h>

void swap(int a,int b)
{
    int t;
    t = a;
    a = b;
    b = t;
    printf("%d %d\n",a,b);
}

int main()
{   
    void swap(int a,int b);
    int a = 4,b = 5;
    swap(a,b);
    printf("%d %d\n",a,b);
    return 0;
}
