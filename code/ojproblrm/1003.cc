#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll gcd(ll n,ll m)
{
    return n % m == 0 ? m : gcd(m,n % m);
}

int main()
{
    ll n,m,ans;
    while(cin >> n >> m){
        if(n == 0 || m == 0)
            break;
       ll x =gcd(n,m);
       ans = (n / x ) * (m / x);
    cout << ans << endl;
    }
}