#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<vector>
#include<cmath>
#define t() int t; cin >> t; while(t --)
#define ll long long
#define ms(i) memset(i, 0, sizeof i)
#define run(i, a, b) for(int i = a; i <= b; i ++)
using namespace std;
#define inf 1e8
const int N=1e6 + 7;
int a[N];
int main()
{
    t()
    {
        ms(a);
        int n;
        scanf("%d", &n);
        run(i, 1, n);
        ll m = 1e10, mn = 0;
        run(i, 1, n)
            if(a[i] < m)
                m = a[i];
        run(i, 1, n)
            if(a[i] == m)
                mn ++;
        ll tp = m;
        run(i, 1, n)
            if(a[i] % tp)
            {
                tp = a[i] % tp;
            }
        if(tp < m)
            puts("1");
        else
        {
            ll ans = (mn + 1) / 2;
            printf("%lld\n", ans);
        }
    }
    return 0;
}