#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

int a[104];
int cnt[1000];

void solve()
{
    int n,c;
    ms(cnt);
    cin >> n >> c;
    int maxx = 0;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
        cnt[a[i]]++;
        maxx = max(a[i],maxx);
    }
    int ans = 0;
    for(int i = 1;i <= maxx;++i){
        if(cnt[i]){
            if(cnt[i] < c){
                ans += cnt[i];
            }
            else{
                ans += c;
            }
        }
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