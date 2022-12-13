#include <stdio.h>
#include <string.h>

#define max 1004
int a[max];

int main()
{ 
    int n,k;
    memset(a,0,sizeof(a));

    while(~scanf("%d %d",&n,&k))
    {
        int i,j;
        for(i = 1;i <= k;++i)
        {
            for(j = 1;j <= n;++j)
            {
                if(j % i == 0)
                    a[j] = !a[j];
            }
        }

        int first = 1;

        for(i = 1;i <= n;++i)
        {
            if(a[i])
            {
                if(first)
                    first = 0;
                else
                    printf(" ");
                printf("%d",i);
            }
        }
    }
    return 0;
}
    
