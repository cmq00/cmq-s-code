#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

void solve()
{
    int n,m;
    cin >> n >> m;
    ll ans = 0;
    ll res = m + m;
    for(int i = 1;i <= m;++i)   ans += i;
    for(int i = 2;i <= n;++i){
        ans += res;
        res += m;
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