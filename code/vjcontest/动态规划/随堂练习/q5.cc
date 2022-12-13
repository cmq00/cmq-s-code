#include <bits/stdc++.h>

using namespace std;

const long long  mod = 2147483648;
int dp[4004];

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;cin >> n;
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        for(int i = 1;i <= n;++i){
            for(int j = i;j <= n;++j){
                dp[i] += dp[j - i];
                dp[i] %= mod;
            }
        }
        cout << dp[n] << endl;
    }
    return 0;
}