#include<bits/stdc++.h>

#define ll long long
#define run(i, a, b) for(ll i = a; i <= b; i ++)
#define rep(i, a, b) for(ll i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
//#define t(i) int t; cin >> t; run(i, 1, t)
#define ms(i) memset(i, 0, sizeof(i))
#define pss pair<int, int>

using namespace std;

ll f(ll x)
{
    ll a, b = 1;
    while(x)
    {
        a = x % 10;
        b *= a;
        x /= 10;
    }
    return b < 10 ? b : f(b);
}
ll ssr(ll r)
{
    ll ans = 0;
    run(i, 1, r)
        ans += f(i);
    return ans;
}
void solve()
{
    ll x;
    cin >> x;
    cout << ssr(x) << endl;
}
int main()
{
    t()
    solve();
    return 0;
}