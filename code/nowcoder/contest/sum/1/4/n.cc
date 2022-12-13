#include<bits/stdc++.h>

#define ll long long
#define lb long double
#define run(i, a, b) for(int i = a; i <= b; i ++)
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

ll gcd(ll n,ll m)
{
    return m ? gcd(m,n % m):n;
}

const ll N = 1e5 + 7;
ll p[23];
ll a[N];
ll b[N];
ll sum;
ll ssr;

void solve()
{
    ll n;
    cin >> n;
    run(i, 1, n)
    {
        cin >> a[i];
        int k = 1;
        run(j, 0, 20)
        {
            if(a[i] & k)
                p[j] ++;
            k <<= 1;
        }
    }
    run(i, 1, n)
    {
        int k = 1;
        run(j, 0, 20)
        {
            if(p[j])
            {
                b[i] += k;
                p[j] --;
            }
            k <<= 1;
        }
        sum += b[i];
    }
    run(i, 1, n)
        ssr += (b[i] * n - sum) * (b[i] * n - sum);
    ll gg = gcd(ssr, n * n * n);
    printf("%lld/%lld\n", ssr / gg, n * n * n / gg);
}

int main()
{
    speed
//    t()
    solve();
    return 0;
}
