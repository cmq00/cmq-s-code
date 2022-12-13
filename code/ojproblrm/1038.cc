#include <bits/stdc++.h>

using namespace std;

int dp[104][1004];
int a[104][1004];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        memset(dp,0,sizeof(dp));

        int n;
        scanf("%d",&n);
        for(int i = 1;i <= n;++i)
            for(int j = 1;j <= 2 * i - 1;++j)
                scanf("%d",&a[i][j]);

        for(int i = n;i >= 1;--i)
            for(int j = 1;j <= 2 * i - 1;++j)
                dp[i][j] = max(max(dp[i + 1][j],dp[i + 1][j + 1]),dp[i + 1][j + 2]) + a[i][j];
                //printf("dp[%d][%d]: %d\n",i,j,dp[i][j]);
        printf("%d\n",dp[1][1]);
    }
    return 0;
}