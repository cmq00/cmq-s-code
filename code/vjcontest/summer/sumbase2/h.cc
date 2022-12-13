#include<bits/stdc++.h>

#define ll long long
//#define lb long double
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
//char buf[100000], *pa = buf, *pd = buf;
//#define gc pa == pd && (pd = (pa = buf) + fread(buf, 1, 100000, stdin), pa == pd) ? EOF: *pa++

using namespace std;

const ll N = 1e6 + 7;
ll n, q;
ll dep[N], son[N], siz[N], fa[N], top[N], tid[N], rid[N], cnt;
ll ct[N], cf[N];
struct tree
{
    ll t, f;
} t[N << 2];

struct edge
{
    int to, nx;
} e[N << 1];

int head[N], tot;
void add(int u, int v)
{
    e[++ tot] = {v, head[u]};
    head[u] = tot;
}

ll gt2(ll n)
{
    ll res = 0;
    while(n)
    {
        if(n % 2 == 0)
            res ++;
        else
            break;
        n >>= 1;
    }
    return res;
}

ll gt5(ll n)
{
    ll res = 0;
    while(n)
    {
        if(n % 5 == 0)
            res ++;
        else
            break;
        n /= 5;
    }
    return res;
}

void dfs1(int s, int f)
{
    fa[s] = f;
    dep[s] = dep[f] + 1;
    siz[s] = 1;
    for(int i = head[s]; i; i = e[i].nx)
    {
        int v = e[i].to;
        if(v == f)
            continue;
        dfs1(v, s);
        siz[s] += siz[v];
        if(siz[son[s]] < siz[v])
            son[s] = v;
    }
}

void dfs2(int s, int f)
{
    ct[s] = gt2(s), cf[s] = gt5(s);
    tid[s] = ++ cnt;
    rid[cnt] = s;
    top[s] = f;
    if(!son[s])
        return;
    dfs2(son[s], f);
    for(int i = head[s]; i; i = e[i].nx)
    {
        int v = e[i].to;
        if(v == fa[s] || v == son[s])
            continue;
        dfs2(v, v);
    }
    ct[s] *= (siz[s] - siz[son[s]]), cf[s] *= (siz[s] - siz[son[s]]);
}

void build(int i, int l, int r)
{
    if(l == r)
    {
        t[i].t = ct[rid[l]], t[i].f = cf[rid[l]];
        return;
    }
    int m(l, r), x(i), y(i);
    build(x, l, m), build(y, m + 1, r);
    t[i].t = t[x].t + t[y].t, t[i].f = t[x].f + t[y].f;
}

ll qq(int i, int l, int r, int ln, int rn, bool z)
{
    if(l > rn || r < ln)
        return 0;
    if(l >= ln && r <= rn)
    {
        if(z)
            return t[i].f;
        return t[i].t;
    }
    int m(l, r), x(i), y(i);
    return qq(x, l, m, ln, rn, z) + qq(y, m + 1, r, ln, rn, z);
}

pair<ll, ll> pathqq(int x)
{
    pair<ll, ll> res;
    res.first = siz[x] * ct[x], res.second = siz[x] * cf[x];
    x = fa[x];
    while(top[x] != 1)
    {
        res.first += qq(1, 1, n, tid[top[x]], tid[x], 0);
        res.second += qq(1, 1, n, tid[top[x]], tid[x], 1);
        x = fa[top[x]];
    }
    res.first += qq(1, 1, n, tid[top[x]], tid[x], 0);
    res.second += qq(1, 1, n, tid[top[x]], tid[x], 1);
    return res;
}

void solve()
{
    cin >> n >> q;
    run(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    dfs1(1, 1);
    dfs2(1, 1);
    build(1, 1, n);
    while(q --)
    {
        int k;
        cin >> k;
        pair<ll, ll> p = pathqq(k);
        cout << min(p.first, p.second) << '\n';
    }
}

int main()
{
    speed
//    t()
    solve();
    return 0;
}
