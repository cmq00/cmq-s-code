#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

void solve()
{
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int len = s.size();
    int cnt = -1;
    int c = 0;
    for(int i = 0;i < len;++i){
        if(s[i] == 'B')
            c++;
        else{
            cnt = max(c,cnt);
            c = 0;
        }
    }
    if(cnt >= k){
        puts("0");
        return ;
    }
    int cntb = 0,cntw = 0;
    int ans = 0;
    for(int i = 0;i <= k - 1;++i){
        if(s[i] == 'B')
            cntb++;
        else
            cntw++;
        ans = cntw;
    }
    //cout << cntw << endl;
    for(int i = 1,j = k;j < len;++i,++j){
        if(s[j] == 'B')
            cntb++;
        else
            cntw++;
        if(s[i] == 'B')
            cntb--;
        else
            cntw--;
        ans = min(ans,cntw); 
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