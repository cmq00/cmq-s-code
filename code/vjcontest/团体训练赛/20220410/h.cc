#include<bits/stdc++.h>

#define ll long long
#define run(i, a, b) for(ll i = a; i <= b; i ++)
#define rep(i, a, b) for(ll i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
#define ms(i) memset(i, 0, sizeof(i))
#define pss pair<int, int>

using namespace std;
const int N = 1e5 + 7, p = 998244353;
ll spow(ll x, ll y)
{
    ll ans = 1;
    while(y){
        if(y & 1)
            ans = ans * x;
        x = x * x;
        y >>= 1;
    }
    return ans;
}

ll n, h, s;
ll dp[307][307];
struct guai
{
    ll h, s, w;
} g[1005];
void DP()
{
    run(i, 1, n)
    {
        rep(j, h, g[i].h + 1)
            rep(k, s, g[i].s - (j - g[i].h - 1))
            {
                if(k >= g[i].s)
                    dp[j][k] = max(dp[j][k], dp[j - g[i].h][k - g[i].s] + g[i].w);
                else
                {
                    ll t = g[i].s - k;
                    dp[j][k] = max(dp[j - g[i].h - t][0] + g[i].w, dp[j][k]);
                }
            }
    }
}
int main()
{
    scanf("%lld%lld%lld", &n, &h, &s);
    run(i, 1, n)
        scanf("%lld%lld%lld", &g[i].h, &g[i].s, &g[i].w);
    DP();
    printf("%lld\n", dp[h][s]);
}