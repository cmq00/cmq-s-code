#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mod = 1e9 + 7;
const int N = 1e6 + 4;

ll fpow(ll base,ll pow)
{
    ll ans = 1;
    while(pow > 0){
        if(pow & 1){
            ans = ans * base % mod;
        }
        pow >>= 1;
        base = base * base % mod;
    }
    return ans;
}

int main()
{
    ll a[N],sum[N];
    for(int i = 1;i <= N - 1;++i){
        a[i] = fpow(2,i - 1);
        sum[i] = (a[i] % mod + sum[i - 1] % mod) % mod;
    }
    int n;
    scanf("%d",&n);
    printf("%lld\n",sum[n]);
    return 0;
}
