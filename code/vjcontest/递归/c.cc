#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int mod = 123456789;
//const ll N = 1e18+10;

int main()
{
    ll N = 1e18 + 10;
    ll a[N];
    a[1] = 1;
    a[2] = 2;
    for(int i = 3;i <= 100;++i){
        a[i] = (2 * a[i - 2] + a[i - 1] + i * i * i) % mod;
    }
    int t;
    scanf("%d\n",&t);
    while(t--){
        ll n;
        scanf("%lld",&n);
        printf("%lld\n",a[n]);
    }
    return 0;
}