#include<bits/stdc++.h>

#define ll long long
#define run(i, a, b) for(ll i = a; i <= b; i ++)
#define rep(i, a, b) for(int i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
//#define t(i) int t; cin >> t; run(i, 1, t)
#define ms(i) memset(i, 0, sizeof(i))
#define pss pair<int, int>

using namespace std;
const int N = 2e5 + 7;
struct yyds
{
    int id, len;
    bool f, ssr;
} a[N];

char s[N];
int p;
int cnt;
int tot;
int ans;

void solve()
{
    ans = 0;
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    run(i, 2, n - 1)
    {
        if(s[i] == 'B')
        {
            if(s[i - 1] == 'A' && s[i + 1] == 'C')
                a[++ p].id = i, a[p].len = 1, a[p].f = 1, a[p].ssr = 0, i ++;
        }
    }
    while(p)
    {
        int x = a[p].len, t = a[p].id;
        if(!a[p].f)
        {
            p --;
            continue;
        }
        if(t - x < 1 || t + x > n || s[t - x] != 'A' || s[t + x] != 'C')
        {
            p --;
            continue;
        }
        if((t % 2 == 0 && !a[p].ssr) || (t % 2 && a[p].ssr))
        {
            ans ++;
            a[p].len ++;
            a[p].ssr ^= 1;
        }
        else
        {
            bool flag = 0;
            rep(i, p - 1, 1)
            {
                if(!a[i].f)
                    continue;
                if((a[i].id % 2 && !a[i].ssr) || (a[i].id % 2 == 0 && a[i].ssr))
                {
                    ans ++;
                    a[i].f = 0;
                    rep(j, p, i + 1)
                        a[j].ssr ^= 1;
                    flag = 1;
                    break;
                }
            }
            if(!flag)
            {
                ans ++;
                p --;
            }
        }
    }
    printf("%d\n", ans);
}

int main()
{
    solve();
    return 0;
}