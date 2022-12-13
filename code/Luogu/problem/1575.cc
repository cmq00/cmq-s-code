#include "bits/stdc++.h"
using namespace std;
int qh[1000]={0};
int main()
{
       int n;
    scanf("%d",&n);

    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(i%j==0) qh[i]+=j;
        }
        if(i==qh[i]) {
            printf("%d,its factors are ", i);
            printf("1");
            for (int j = 2; j <= i; j++) {
                if(i%j==0)
                    printf(",%d",j);
            }
            printf("\n");
        }
        else continue;
    }
    return 0;
}