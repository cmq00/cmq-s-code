#include <stdio.h>

int main()
{
    int m,n,r,t;
    scanf("%d %d",&m,&n);
    int p = m * n;
    if(n < m){
        t = n;
        n = m;
        m = t;
    }
    while( m!= 0){
        r = n % m;
        n = m;
        m = r;
    }
    printf("%d,%d",m,r);

    printf("%d\n",n);
    printf("%d\n",p / n);
    return 0;
}

