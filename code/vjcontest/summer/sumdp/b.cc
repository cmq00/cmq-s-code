#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

void solve()
{
    ll m,s,t;
    cin >> m >> s >> t;
    int dp[t + 4];
    dp[0] = 0;
    for(int i = 1;i <= t;++i){
        //cout << m << " ";
        dp[i] = 0;
        if(m >= 10){
            dp[i] = dp[i - 1] + 60;
            m -= 10;
        }
        else{
            ll lt = t - i + 1;
            ll rt = (10 - m) / 4 + 1;
            if(lt - rt > 1){
                ll s = (rt + 1) * 17;
                if(s >= 60)
                    dp[i] = dp[i - 1] + 17;
                else
                    dp[i] = dp[i - 1],m += 4;
            }
            else
                dp[i] = dp[i - 1] + 17;
        }
    }
    ll ans = 0;
    for(int i = 1;i <= t;++i){
        //cout << dp[i] << " ";
        if(dp[i] >= s){
            puts("Yes");
            cout << i << endl;
            return;
        }
        else
            ans = dp[i];
    }
    puts("No");
    cout << ans << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}