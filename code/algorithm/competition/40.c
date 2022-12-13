#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define max 20
int a[max][max];

int main()
{
    int n;
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    int num = 1;
    int i = 1,j = n;
    a[i][j] = 1;
    
    while(num < n * n)
    {
            while(i + 1 <= n && !a[i + 1][j])
                a[++i][j] = ++num;
            while(j - 1 >= 1 && !a[i][j - 1])
                a[i][--j] = ++num;
            while(i - 1 >= 1 && !a[i - 1][j])
                a[--i][j] = ++num;
            while(j + 1 <= n && !a[i][j + 1])
                a[i][++j] = ++num;

    }
    for(int i = 1;i <= n;++i)
    {
        for(int j = 1;j <= n;++j)
        {
            printf("%3d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}


        

