#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 500;
int a[N];

void solve()
{
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= k;++i){
        cin >> a[i];
    }
    int ans = -1;
    int res1 = n - a[k] + 1;
    int res2 = a[1];
    sort(a + 1,a + 1 + k);
    for(int i = 1;i <= k;++i)
        ans = max((a[i] - a[i - 1]) / 2,ans);
    //cout << res1 << " " << " " << ans << " " << res2 << endl;
    cout << max(res1,max(ans + 1,res2)) << endl;
    
}
int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}