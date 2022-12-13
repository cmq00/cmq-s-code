#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 1e7 + 4;
int isprime[N];
vector<ll> v;

ll gcd(ll n,ll m)
{
    return m ? gcd(m,n % m):n;
}

long long fpow(long long base, long long power){
    long long res = 1;
    while (power > 0) {
        if (power & 1) {
            res = res * base;
        }
        power >>= 1;
        base = base * base;
    }
    return res;
}

void aiPrime(int n)
{
    memset(isprime,true,sizeof(isprime));
    isprime[1] = isprime[0] = false;
    for(ll i = 2;i <= n;++i){
        if(isprime[i]){
            v.push_back(i);
            for(ll j = i;j * i <= n;++j)
                  isprime[j * i] = false;
        }
    }
}

void solve()
{
    ll l,r,k;
    scanf("%lld %lld %lld",&l,&r,&k);
    ll cnt = 0;
    vector<ll> v2;
    for(int i = 0;i < v.size();++i){
        //cout << v[i] << " ";
        if(fpow(v[i],k) > r)
            break;
        v2.push_back(fpow(v[i],k));
    }
    //cout << endl;
    //cout << v2.size() << endl;
    for(int i = 0;i < v2.size();++i){
        //cout << v2[i] << " ";
        cnt += r / v2[i] - (l - 1) / v2[i];
    }
    //cout << "cnt :" << cnt << endl;
    ll pos = v2.size() - 1;
    for(int i = 0;i < pos;++i){
        for(int j = 0;j < i;++j){
            if(i == j)
                continue;
            ll x = v2[i] * v2[j];
            //cout << "x: " << x << " "; 
            if(x > r){
                pos = j - 1;
                break;
            }
            ll xx = x / gcd(v2[i],v2[j]);
            //cout << xx << " " << "r / xx" << r / xx << " ";
            if(l <= xx && xx <= r)
                cnt -= r / xx - (l - 1) / xx;
        }
    }
    cout << r - l + 1 - cnt << endl;
}

int main()
{
    aiPrime(N - 2);
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}