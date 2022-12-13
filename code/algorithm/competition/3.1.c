#include <stdio.h>

int main()
{
    int a[100],n = 0,x,i;
    while(scanf("%d",&x) == 1)
        a[n++] = x;
    for(i = n - 1;i >= 0;--i)
        printf("%d",a[i]);
    printf("\n");
    return 0;
}


