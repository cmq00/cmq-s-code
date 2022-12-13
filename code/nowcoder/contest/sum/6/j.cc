#include<bits/stdc++.h>

#define ll long long
#define lb long double
#define run(i, a, b) for(ll i = a; i <= b; i ++)
#define rep(i, a, b) for(int i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
//#define t(i) int t; cin >> t; run(i, 1, t)
#define ms(i) memset(i, 0, sizeof(i))
#define pss pair<int, int>
#define speed ios::sync_with_stdio(0); cin.tie(0);
char buf[100000], *pa = buf, *pd = buf;
#define gc pa == pd && (pd = (pa = buf) + fread(buf, 1, 100000, stdin), pa == pd) ? EOF: *pa++

using namespace std;

const ll N = 1e6 + 7;

void solve()
{
    ll a, b, c, x;
    cin >> a >> b >> c >> x;
    ll b1 = b, b2 = a - b;
    ll c1 = c, c2 = b1 - c, c3 = b2 - c;
    if(x == c1 || x == c2 || x == c3)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
}

int main()
{
    speed
    t()
    solve();
    return 0;
}
