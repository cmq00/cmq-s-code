#include <stdio.h>

int main()
{
    void inv(int *x,int n);
    int i,a[10],*p = a;

    for(i = 0;i < 10;i++,p++)
        scanf("%d",p);
    printf("\n");
    p = a;

    inv(p,10);

    for(p = a;p < a + 10;p++)
        printf("%d ",*p);
    printf("\n");

    return 0;
}

void inv(int *x,int n)
{
    int *i,*p,t,*j,m = (n - 1)/2;
    i = x;
    j = x + n -1;
    p = x + m;
    for(;i <= p;i++,j--){
        t = *i;
        *i = *j;
        *j = t;
    }
    return;
}
