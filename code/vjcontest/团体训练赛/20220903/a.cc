#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

ll gcd(ll n,ll m)
{
    return m ? gcd(m,n % m):n;
}

void solve()
{
    ll p,q,a,b;
    cin >> p >> q;
    ll t = p * p - 4 * q * q;
    int gt = sqrt(t);
    if(t < 0 || gt * gt != t){
        puts("0 0");
        return;
    }
    ll tt = p + sqrt(t);
    a = q * tt;
    b = tt;
    // ll gd = gcd(a,b);
    // a /= gd;
    // b /= gd;
    // if(a > b)
    //     swap(a,b);
    cout << a << " " << b << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}