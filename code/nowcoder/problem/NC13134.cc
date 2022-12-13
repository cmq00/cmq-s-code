#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 4;
int dp1[N],dp2[N],a[N];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;++i)
        scanf("%d",&a[i]),dp1[i] = 1,dp2[i] = 1;
    
    for(int i = 2;i <= n;++i){
        for(int j = 1;j <= n;++j){
            if(a[j] < a[i])
                dp1[i] = max(dp1[i],dp1[j] + 1);
        }
        if(dp1[i - 1] == dp2[i - 1])
            dp2[i] = 
    }

    int ans = -1;
    for(int i = 1;i <= n;++i)
        ans = max(ans,dp[i]);
    printf("%d\n",ans);
    return 0;
}