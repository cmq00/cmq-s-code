#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mod = 1e9 + 7;
const int N = 1e5 + 4;

int main()
{
    ll a[N],sum[N];
    int n = N - 2;
    a[1] = 1,a[2] = 2;
    sum[1] = 1,sum[2] = 3;
    for(int i = 3;i <= n;++i){
        a[i] = a[i - 1] + i - 1;
        sum[i] = (a[i] % mod + sum[i - 1] % mod) % mod;
    }
    int x;
    scanf("%d",&x);
    printf("%lld\n",sum[x]);
    return 0;
}