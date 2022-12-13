#include<bits/stdc++.h>

#define ll long long
#define run(i, a, b) for(ll i = a; i <= b; i ++)
#define rep(i, a, b) for(ll i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
#define ms(i) memset(i, 0, sizeof(i))

using namespace std;
const int N = 1e5 + 5;
ll a[100];
int main()
{
    ll n, k;
    ll cnt = 0;
    bool f = 0;
    scanf("%lld%lld", &n, &k);
    rep(i, 32, 0)
    if((n >> i) & 1)
    {
        a[i] ++;
        n -= 1 << i;
    }
    rep(i, 32, 0)
    cnt += a[i];
    if(cnt > k)
        f = 0;
    else if(cnt == k)
    {
        f = 1;
    }
    else
    {
        rep(i, 32, 0)
        {
            if(a[i])
            {
                if(k - cnt <= a[i])
                {
                    if(!i)
                        continue;
                    f = 1;
                    a[i] -= (k - cnt);
                    a[i - 1] += 2 * (k - cnt);
                    break;
                }
                else
                {
                    if(!i)
                        continue;
                    a[i - 1] += 2 * a[i];
                    cnt += a[i];
                    a[i] = 0;
                }
            }
            if(cnt == k)
            {
                f = 1;
                break;
            }
        }
    }
    if(!f)
        puts("NO");
    else
    {
        puts("YES");
        run(i, 0, 32)
        for(ll j = 1; j <= a[i]; j ++)
            printf("%d ", 1 << i);
        puts("");
    }
}