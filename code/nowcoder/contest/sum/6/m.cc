#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

char mp[504][504];
int dp[504][504];

void solve()
{
    ms(dp);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= m;++j){
            cin >> mp[i][j];
        }
    }
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= m;++j){
            
        }
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}