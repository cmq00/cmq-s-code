#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll gcd(ll n,ll m)
{
    return m ? gcd1(m,n % m):n;
}

/*ll gcd2(ll n,ll m)
{
    while(m > 0){
        ll x = n % m;
        n = m;
        m = x;
    }
    return n;
}*/

int main()
{
    ll n,m;
    while(~scanf("%lld %lld",&n,&m)){
        ll ans1 = gcd1(n,m);
        ll ans2 = n * m / ans1;
        printf("%lld %lld\n",ans1,ans2);

    }
    return 0;
}

