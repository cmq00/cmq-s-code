#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 4;
int n;
int a[N],vis[N];

void solve()
{
    memset(vis,0,sizeof(vis));
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
    }
    for(int i = 2;i <= n - 1;++i)
        if(a[i] > a[i - 1] && a[i] > a[i + 1])
            vis[i] = 1;
    int ans = 0;
    for(int i = 1;i <= n;++i){
        if(vis[i] == 1){
            ans++;
            if(vis[i + 2] == 1){
                vis[i + 2] = 0;
                a[i + 1] = max(a[i],a[i + 2]);
            }
            else    
                a[i + 1] = a[i];
        }
    }
    cout << ans << endl;
    for(int i = 1;i <= n;++i)
        cout << a[i] << " ";
    cout << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}