#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 1004;
int w[N];
int v[N];
int b[N];
int g[N][N];
int dp[N];

void solve()
{
    int m,n,t = 0;
    cin >> m >> n;
    for(int i = 1;i <= n;++i){
        int x;
        cin >> w[i] >> v[i] >> x;
        t = max(t,x);
        b[x]++;
        g[x][b[x]] = i;
    }
    //cout << "t: " << t << endl;
    for(int i = 1;i <= t;++i){
        for(int j = m;j >= 0;--j){
            for(int k = 1;k <= b[i];++k){
                if(j >= w[g[i][k]]){
                    dp[j] = max(dp[j],dp[j - w[g[i][k]]] + v[g[i][k]]);
                }
            }
        }
    }
    cout << dp[m] << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}
