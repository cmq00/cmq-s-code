#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll a[5004],b[5004];
ll dp[5004][5004];

int main()
{
    int n;

    scanf("%d",&n);
    for(int i = 1;i <= n;++i)
        scanf("%lld",&a[i]);
    
    ll sum = 0;
    for(int i = 1;i <= n;++i){
        scanf("%lld",&b[i]);
        sum += a[i] * b[i];
    }
    //printf("sum: %lld\n",sum);
    /*for(int i = 1;i <= n;++i)
        for(int j = 1;j <= n;++j)
            dp[i][j] = sum;*/
    ll ans = 0;
    for(int i = n;i >= 1;--i){
        for(int j = i + 1;j <= n;++j){
            dp[i][j] = dp[i + 1][j - 1] - a[i] * b[i] - a[j] * b[j] + a[i] * b[j] + a[j] * b[i];
            ans = max(ans,dp[i][j]);
        }
    }
    printf("%lld\n",ans + sum);
    return 0;
}