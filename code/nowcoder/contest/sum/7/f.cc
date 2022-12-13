#include<bits/stdc++.h>

#define ll long long
//#define lb long double
#define run(i, a, b) for(int i = a; i <= b; i ++)
#define rep(i, a, b) for(int i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
//#define t(i) int t; cin >> t; run(i, 1, t)
#define ms(i) memset(i, 0, sizeof(i))
#define pss pair<int, int>
#define speed ios::sync_with_stdio(0); cin.tie(0);
//char buf[100000], *pa = buf, *pd = buf;
//#define gc pa == pd && (pd = (pa = buf) + fread(buf, 1, 100000, stdin), pa == pd) ? EOF: *pa++

using namespace std;

const ll N = 1e6 + 7;
ll aa[N], bb[N];
unordered_map<ll, ll> mp;

void solve()
{
    mp.clear();
    ll n, m, p, x, a, b, c;
    cin >> n >> m >> p >> x >> a >> b >> c;
    run(i, 1, n)
    {
        x = (x * x % p * a % p + b * x % p + c) % p;
        aa[i] = x;
        if(!mp[x])
        mp[x] = i;
    }
    ll ans = 0;
    run(j, 1, m)
    {
        x = (x * x % p * a % p + b * x % p + c) % p;
        if(mp[x])
            ans = max(ans, min(n - mp[x] + 1, m - j + 1));
    }
    cout << ans << '\n';
}


int main()
{
    speed
    t()
    solve();
    return 0;
}

