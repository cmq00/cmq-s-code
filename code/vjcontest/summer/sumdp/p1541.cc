#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

int a[1004],b[1004],cnt[10];
int dp[41][41][41][41];

void solve()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
    }
    for(int i = 1;i <= m;++i){
        int x;
        cin >> x;
        cnt[x]++;
    }
    dp[0][0][0][0] = a[1];
    for(int i = 0;i <= cnt[1];++i){
        for(int j = 0;j <= cnt[2];++j){
            for(int k = 0;k <= cnt[3];++k){
                for(int l = 0;l <= cnt[4];++l){
                    int now = 1 * i + 2 * j + 3 * k + 4 * l + 1;
                    if(i)
                        dp[i][j][k][l] = max(dp[i][j][k][l],dp[i - 1][j][k][l] + a[now]);
                    if(j)
                         dp[i][j][k][l] = max(dp[i][j][k][l],dp[i][j - 1][k][l] + a[now]);
                    if(k)
                         dp[i][j][k][l] = max(dp[i][j][k][l],dp[i][j][k - 1][l] + a[now]);
                    if(l)
                         dp[i][j][k][l] = max(dp[i][j][k][l],dp[i][j][k][l - 1] + a[now]);
                }
            }
        }
    }
    cout << dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]] << endl;
}   

int main()//https://www.luogu.com.cn/problem/P1541
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}