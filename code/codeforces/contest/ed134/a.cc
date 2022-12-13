#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

bool vis[1004];

void solve()
{
    memset(vis,0,sizeof(vis));
    int cnt = 0;
    for(int i = 1;i <= 2;++i){
        for(int j = 1;j <= 2;++j){
            char ch;
            cin >> ch;
            if(!vis[ch - 'a']){
                vis[ch - 'a'] = 1;
                cnt++;
            }
        }
    }
    int ans = 0;
    if(cnt == 1){
        ans = 0;
    }
    if(cnt == 2)
        ans = 1;
    if(cnt == 3)
        ans = 2;
    if(cnt == 4)
        ans = 3;
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