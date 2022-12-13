#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 4;
const int mod = 998244353;

ll a[N];

ll fp(ll base, ll power) {
    long long result = 1;
    while (power > 0) {
        if (power & 1) {
            result = result * base % mod;
        }
        power >>= 1;
        base = (base * base) % mod;
    }
    return result;
}

void solve()
{
    int n;
    cin >> n;
    //vector<ll> v;
    ll res = 1;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
        res = ((res % mod) * (a[i] % mod)) % mod;
            //res *= a[i] % mod;
            //res %= mod;
    }
    for(int i = 1;i <= n;++i){
        ll ret = fp(a[i],mod - 2);
        cout << ((res % mod) * (ret % mod)) % mod << " ";
    }
    cout << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}