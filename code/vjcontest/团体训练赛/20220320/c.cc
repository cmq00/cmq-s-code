#include<bits/stdc++.h>

#define ll long long
#define run(i, a, b) for(int i = a; i <= b; i ++)
#define rep(i, a, b) for(int i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
#define ms(i) memset(i, 0, sizeof(i))

using namespace std;
map<int, bool> mp;
int main()
{
    ll a, b, m, x, ans;
    bool f = 0;
    scanf("%lld%lld%lld%lld%lld", &a, &b, &m, &x, &ans);
    while(1)
    {
        if(x == ans)
        {
            f = 1;
            break;
        }
        if(mp[x])
            break;
        mp[x] = 1;
        x = ((x * a) + b) % m;
    }
    if(f)
        puts("YES");
    else
        puts("NO");
}