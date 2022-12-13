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

using namespace std;

void solve()
{
    int n;
    scanf("%d", &n);
    if(n == 1)
    {
        puts("1");
        puts("1");
        return;
    }
    if(n == 2 || n == 3)
    {
        puts("2");
        printf("%d %d\n", 2, 2);
        return;
    }
    printf("%d\n", n);
    printf("%d %d ", 2, 2);
    run(i, 3, n - 2)
        printf("%lld ", i);
    printf("%d %d\n", n - 1, n - 1);
}
int main()
{
    solve();
    return 0;
}