#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))

using namespace std;

const int N = 1e5 + 4;
int dp[N];
int a[N];
int n;
map<int,int> mp;

int main()
{
    while(scanf("%d",&a[++n])!=EOF);
    // cin >> n;
    // for(int i = 1;i <= n;++i){
    //     cin >> a[i];
    // }
    n --;
    dp[1] = 1;
    int ans = 0;
    for(int i = 2;i <= n;++i){
        dp[i] = 1;
        for(int j = 1;j < i;++j){
            if(a[j] >= a[i]){
                dp[i] = max(dp[j] + 1,dp[i]);
                ans = max(ans,dp[i]);
            }
        }
    }
    // for(int i = 1;i <= n;++i)
    //     cout << dp[i] << " ";
    // cout << endl;
    int cnt = 0;
    dp[1] = 1;
    for(int i = 2;i <= n;++i){
        dp[i] = 1;
        for(int j = 1;j < i;++j){
            if(a[j] < a[i]){
                dp[i] = max(dp[j] + 1,dp[i]);
                cnt = max(cnt,dp[i]);
            }
        }
    }
    cout << ans << endl;
    cout << cnt << endl;
}