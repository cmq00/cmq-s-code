#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 32004;
int v[N],w[N],p[N];
int b[N];
int g[N][4];
int dp[N];
map<int,int> mp;

void solve()
{
    int n,m;
    cin >> n >> m;
    int t = 0;
    for(int i = 1;i <= m;++i){
        cin >> v[i] >> w[i] >> p[i];
        if(p[i] == 0){
            t++;
            b[t]++;
            g[t][b[t]] = i;
            mp[i] = t;
        }
    }
    for(int i = 1;i <= m;++i){
        if(p[i]){
            int x = mp[p[i]];
            b[x]++;
            g[x][b[x]] = i;
        }
    }
    // for(int i = 1;i <= t;++i){
    //     for(int j = 1;j <= b[i];++j){
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for(int i = 1;i <= t;++i){
        for(int j = n;j >= 0;--j){
           // for(int k = 1;k <= b[i];++k){
                if(j >= v[g[i][1]]){
                    dp[j] = max(dp[j],dp[j - v[g[i][1]]] + v[g[i][1]] * w[g[i][1]]);
                }
                if(j >= v[g[i][1]] + v[g[i][2]]){
                    dp[j] = max(dp[j],dp[j - v[g[i][1]] - v[g[i][2]]] + v[g[i][1]] * w[g[i][1]] + v[g[i][2]] * w[g[i][2]]);
                }
                if(j >= v[g[i][1]] + v[g[i][3]]){
                    dp[j] = max(dp[j],dp[j - v[g[i][1]] - v[g[i][3]]] + v[g[i][3]] * w[g[i][3]]);
                }
                if(j >= v[g[i][1]] + v[g[i][2]] + v[g[i][3]]){
                    dp[j] = max(dp[j],dp[j - v[g[i][1]] - v[g[i][2]] - v[g[i][3]]] + v[g[i][1]] * w[g[i][1]] + v[g[i][2]] * w[g[i][2]] + v[g[i][3]] * w[g[i][3]]);
                }
           // }
        }
    }
    //cout << dp[800] << " " << dp[100] << " " << dp[400] << " " << dp[500] << " " << endl;
    cout << dp[n] << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}