#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int t,n,m,dp[10005],v[10005];

int main()
{
    scanf("%d",&t);
    while(t--){
        memset(dp,0,sizeof(dp));
        scanf("%d %d",&n,&m);
        for(int i = 1;i <= n;++i)
            scanf("%d",&v[i]);
        dp[0] = 1;
        for(int i = 1;i <= n;++i){
            for(int j = m;j >= v[i];--j){
                dp[j] += dp[j - v[i]];
                dp[j] %= mod;                
            }
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}