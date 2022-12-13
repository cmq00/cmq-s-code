#include <bits/stdc++.h>

using namespace std;

int a[100];
int vis[100][100];
int dp[100];

int main()
{
    int n;
    map<int,int> mp;
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
    dp[i] = a[i];
    }
    for(int i = 1;i < n;++i){
        for(int j = i + 1;j <= n;++j){
            int x;
            cin >> x;
            if(x == 1)
                vis[i][j] = 1;
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= i;++j){
            if(vis[j][i]){
                if(a[i] + dp[j] > dp[i])
                    mp[i] = j;
                dp[i] = max(dp[i],a[i] + dp[j]);
            }
        }
    }
    int pos = 0;
    for(int i = 1;i <= n;++i){
        //cout << dp[i] << " ";
        if(dp[i] > ans)
            pos = i;
        ans = max(ans,dp[i]);
    }
    int a[100];
    int j = 0;
    a[j++] = pos;
    while(mp[pos]){
        //cout << mp[pos] << " ";
        a[j++] = mp[pos]; 
        pos = mp[pos];
    }
    for(int i = j - 1;i >= 0;--i)
        cout << a[i] << " ";
    cout << endl;
    cout << ans << endl;
    return 0;
}