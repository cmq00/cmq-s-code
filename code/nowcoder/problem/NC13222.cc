#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e3;
ll a[N + 1004],b[N + 1004];

ll fun(ll a,ll b)
{
    return (a - b) * (a - b);
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;++i)
        scanf("%lld",&a[i]);
    int m;
    scanf("%d",&m);
    for(int i = 1;i <= m;++i)
        scanf("%lld",&b[i]);
    
    ll ans = 1e9;
    for(int i = 1;i <= m - n;++i){
        ll anss = 0;
        for(int j = 0;j < n;++j){
           anss += fun(a[1 + j],b[i + j]);
        }
        ans = min(ans,anss);
    }
    printf("%lld\n",ans);
    return 0;
}