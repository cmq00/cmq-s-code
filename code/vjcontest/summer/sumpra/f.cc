#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 1e6 + 4;
ll a[N];
ll dp[1004][1003];

void solve()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
        a[i] %= m;
    }
    if(n > m){
        puts("YES");
        return ;
    }
    for(int i = 1;i <= n;++i){
        dp[i][a[i]] = 1;
        for(int j = 0;j <= m;++j){
            if(dp[i - 1][j]){
                dp[i][j] = dp[i - 1][j];
                dp[i][(j + a[i]) % m] = 1;
            }
        }
    }
    if(dp[n][0])
        puts("YES");
    else
        puts("NO");
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}