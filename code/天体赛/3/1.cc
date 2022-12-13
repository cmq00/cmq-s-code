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
const int N = 3e5 + 7, p = 1e9 + 7;
ll n, m, k, q;
ll spow(ll x, ll y)
{
    ll ans = 1;
    while(y > 0)
    {
        if(y & 1)
            ans = ans * x % p;
        y >>= 1;
        x = x * x % p;
    }
    return ans;
}
ll wing[N];
int main()
{
    ll ssr = 1;
    run(i, 1, N)
    {
        ssr = ssr * i % p;
        wing[i] = ssr;
    }
    t()
    {
        ll fine = 1;
        scanf("%lld%lld%lld%lld", &n, &m, &k, &q);
        if(k > n)
            puts("0");
        else
        {
            ll a, b, c;
            a = wing[n], b = wing[m + 1], c = wing[n + m];
            ll invc = spow(c, p - 2);
            ll ssr = a * b % p * invc % p;
            ssr = spow(ssr, q);
            printf("%lld\n", ssr);
        }
    }
}
