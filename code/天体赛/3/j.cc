#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e8 + 7;
bool isprime[N];

void aiprime(int n)
{
    memset(isprime,true,sizeof(isprime));
    isprime[1] = isprime[0] = false;
    for(ll i = 2;i <= n;++i){
        if(isprime[i]){
            for(ll j = i;j * i <= n;++j)
                isprime[j * i] = false;
        }
    }
}

ll fp(ll base,ll pow,ll mod)
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

void solve()
{
    ll n,m,p;
    cin >> n >> m >> p;
    if(!isprime[p])
        cout << fp(n,m,p) << endl;
    else{

    }
}

int main()
{
    //ios_base::sync_with_stdio(0);
    aiprime(N - 2);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}