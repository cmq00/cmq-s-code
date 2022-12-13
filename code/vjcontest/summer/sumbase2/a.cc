#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

int dp[104][1004];
int t[104];
int v[104];
int d[1004];

void solve()
{
    int T,m;
    cin >> T >> m;
    for(int i = 1;i <= m;++i){
        cin >> t[i] >> v[i];
    }
    // for(int i = 1;i <= m;++i){
    //     for(int j = 1;j <= T;++j){
    //         if(j < t[i])
    //             dp[i][j] = dp[i - 1][j];
    //         else
    //             dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - t[i]] + v[i]);
    //     }
    // }
    // cout << dp[m][T] << endl;
    for(int i = 1;i <= m;++i){
        for(int j = T;j >= t[i];--j){
            d[j] = max(d[j],d[j - t[i]] + v[i]);
        }
    }
    cout << d[T] << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}