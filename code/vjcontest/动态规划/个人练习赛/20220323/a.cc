#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a[100000];
const int maxx = 1e9;

void solve()
{
    int n;
    cin >> n;
    vector<ll> v;
    ll cnt = 1;
    if(n % 2 == 0)
        n /= 2;
    while(n){
        int x = n & 1;
        v.push_back(x);
        cnt *= 2;
        n >>= 1;
    }
    ll ans = 0;
    int len = v.size();
    //for(int i = 0;i < len;++i)
        //cout << v[i] << " ";
    //cout << endl;
    for(int i = 0;i <= len - 2;++i)
        ans += v[i];
    cout << ans + 1 << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;
    while(T--) solve();
    return 0;
}
