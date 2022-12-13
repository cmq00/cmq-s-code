#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int p = 131;
ll Hs[4][1004];

void solve()
{
    int n;
    cin >> n;
    map<ll,ll> mp;
    vector<string> v[4];
    for(int i = 1;i <= 3;++i){
        for(int j = 1;j <= n;++j){
            string s;
            cin >> s;
            v[i].push_back(s);
            int hs = 0;
            for(int k = 0;k < 3;++k){
                hs = hs * p + s[k];
            }
            mp[hs]++;
            Hs[i][j - 1] = hs;
        }
    }
    for(int i = 1;i <= 3;++i){
        int ans = 0;
        for(int j = 0;j < v[i].size();++j){
            if(mp[Hs[i][j]] == 1)
                ans += 3;
            if(mp[Hs[i][j]] == 2)
                ans += 1;
        }
        cout << ans << " ";
    }
    puts("");
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}