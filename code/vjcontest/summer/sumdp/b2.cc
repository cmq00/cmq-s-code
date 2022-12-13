#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 3e5 + 4;
int dp[N];

void solve()
{
    int m,s,t;
    cin >> m >> s >> t;
    for(int i = 1;i <= t;++i){
        if(m >= 10){
            dp[i] = dp[i - 1] + 60;
            m -= 10;
        }
        else{
            dp[i] = dp[i - 1];
            m += 4;
        }
    }
    for(int i = 1;i <= t;++i){
        if(dp[i] < dp[i - 1] + 17)
            dp[i] = dp[i - 1] + 17;
        if(dp[i] >= s){
            puts("Yes");
            cout << i << endl;
            return ;
        }
    }
    puts("No");
    cout << dp[t] << endl;
}

int main()//https://www.luogu.com.cn/problem/P1095
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}