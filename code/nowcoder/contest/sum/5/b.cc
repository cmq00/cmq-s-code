#include<bits/stdc++.h>

#define ll long long
#define lb long double
#define run(i, a, b) for(ll i = a; i <= b; i ++)
#define rep(i, a, b) for(ll i = a; i >= b; i --)
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

const ll N = 1e5 + 7, p = 1e15;
ll a[N];
int n, mon;

ll lowbit(ll x)
{
    return x & -x;
}

ll spow(ll x, ll y)
{
    ll res = 1;
    while(y)
    {
        if(y & 1)
            res = (res * x) % p;
        x = (x * x) % p;
        y >>= 1;
    }
    return res;
}

ll read()
{
    int f(1);
    ll res(0);
    char c(gc);
    for(; c > '9' || c < '0'; c = gc)
        if(c == '-')
            f = -1;
    for(; c >= '0' && c <= '9'; c = gc)
        res = (res << 1) + (res << 3) + (c ^ 48);
    return res * f;
}

bool yyds(ll x)
{
    priority_queue<ll, vector<ll>, greater<ll> > q;
    ll mm = mon;
    run(i, 1, n) q.push(a[i] + x * i);
    ll cnt = 0;
    while(!q.empty())
    {
        if(cnt >= x)
            return 1;
        mm -= q.top();
        q.pop();
        if(mm >= 0)
        {
            cnt ++;
            if(cnt >= x)
                return 1;
        }
        else
            break;
    }
    if(cnt >= x)
        return 1;
    return 0;
}

void solve()
{
    while(cin >> n >> mon)
    {
        run(i, 1, n) cin >> a[i];
        ll l = 0, r = n;
        while(l <= r)
        {
            ll m(l, r);
            if(yyds(m))
                l = m + 1;
            else
                r = m - 1;
        }
        cout << r << '\n';
    }
}

int main()
{
    speed
//    t()
    solve();
    return 0;
}