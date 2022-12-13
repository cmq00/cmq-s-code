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
#define speed ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

const ll N = 1e6 + 7;
int g[N];

void init()
{
    g[1] = 1;
    ll l = 2;
    run(i, 2, N)
    {
        ll r = i * i;
        if(r >= N)
        {
            run(j, l, N)
            g[j] = i;
            return;
        }
        run(j, l, r)
        g[j] = i;
        l = r + 1;
    }
}

void solve()
{
    int n;
    cin >> n;
    int ssr = (n - 1) % g[n] + 1, ac = n / g[n];
    if(n % g[n] == 0) ac --;
    rep(i, ssr, 1)
        printf("%d ", i);
    run(i, 1, ac)
    {
        run(j, 0, g[n] - 1)
            printf("%d ", g[n] * i - j + ssr);
    }
    puts("");
}

int main()
{
    init();
    speed
    t()
    solve();
    return 0;
}
