#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;
const int N = 204;
const int mod = 1e9 + 7;
int dp[N][N][N];
char s[N];

void solve()
{
    int n,m;
    cin >> n >> m;
    cin >> s + 1;
    //cout << s + 1 << endl;
    for(int i = 0;i <= m;++i){
        for(int j = 0;j <= n;++j){
            for(int k = 0;k <= m;++k)
                dp[i][j][k] = 0;
        }
    }
    dp[0][0][0] = 1;
    for(int i = 0;i <= m;++i){
        for(int j = 0;j <= i;++j){
            for(int k = 0;k <= i;++k){
                if(dp[i][j][k] == 0)
                    continue;
                //(
                int t = j + (s[j + 1] == '(');
                dp[i + 1][t][k + 1] = (dp[i + 1][t][k + 1] + dp[i][j][k]) % mod;
                //)
                t = j + (s[j + 1] == ')');
                if(k)
                    dp[i + 1][t][k - 1] = (dp[i + 1][t][k - 1] + dp[i][j][k]) % mod;
            }
        }
    }
    cout << dp[m][n][0] << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}