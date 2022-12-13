#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int mod = 998244353;

ll qpow(ll x,ll y){
    ll num = 1;
    for (;y;y>>=1){
        if (y&1) num = num * x %mod;
        x = x * x % mod;
    }
    return num;
}

void solve()
{
    for(int i = 1;i <= 8;++i)
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}   