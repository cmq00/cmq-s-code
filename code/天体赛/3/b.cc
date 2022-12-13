#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3e5 + 4;
const int mod = 1e9 + 7;
ll a[N];

ll fp(ll base,ll pow)
{
    ll res = 1;
    while(pow > 0){
        if(pow & 1)
            res = ((base % mod) * (res % mod)) % mod;
            //res = res * base % mod;
        pow >>= 1;
        base = ((base % mod) * (base % mod)) % mod;
    }
    return res;
}

void prework()
{
    a[0] = 1;
    for(int i = 1;i <= N - 4;++i){
        a[i] = (i * a[i - 1] % mod) % mod;
    }
}
void solve()
{
    ll n,m,k,p;
    cin >> n >> m >> k >> p;
    ll res1 = 0;
    ll res2 = 0;
    if(n < k){
        cout << "0" << endl;
        return ;
    }
    res1 = a[n + m] * fp(a[n + m - k],mod - 2) % mod;
    res2 = a[n] * fp(a[n - k],mod - 2) % mod;
    //cout << a[n] << " " << a[n - k] << endl;
    //printf("res1 %d res2 :%d\n",res1,res2);
    ll ans = res2 * fp(res1,mod - 2) % mod;
    cout << fp(ans,p) << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    prework();
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}