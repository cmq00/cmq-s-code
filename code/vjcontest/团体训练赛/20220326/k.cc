#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a[200];

void solve()
{
    int n,m;
    cin >> n >> m;
    ll ans = 0;
    for(int i = 1;i <= n;++i){
        ans += i * i * m;
    }
    cout << ans << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}