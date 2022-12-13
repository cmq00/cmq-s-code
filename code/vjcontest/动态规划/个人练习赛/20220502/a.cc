#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 4e5 + 10;
int a[N];

void solve()
{
    int n,k;
    int maxx = 0;
    cin >> n >> k;
    int cnt[n + 4];
    ms(cnt);
    for(int i = 1;i <= k;++i){
        cin >> a[i];
        //cnt[a[i]]++;
       // maxx = max(maxx,a[i]);
    }
    sort(a + 1,a + 1 + k);
    int ans = k;
    int pos = 0;
    for(int i = k;i >= 1;--i){
        //if(cnt[a[i]] == 0) break;
        int len = n - a[i];
        //cnt[a[i]]--;
        for(int j = pos + 1;j <= pos + len;++j){
            ans -= 1;
        }
        pos += len;
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