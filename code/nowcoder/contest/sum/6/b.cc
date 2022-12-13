#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 2e6 + 4;

int ans[N];
int dis[N];
map<int,int> mp;

void solve()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n - 1;++i){
        int u,v;
        cin >> u >> v;
        mp[v] = u;
    }
    for(int i = 1;i <= n;++i){
        cin >> dis[i];
    }
    for(int i = 1;i <= n;++i){
        //cout << i << " " << ans[i] << endl;
        ans[i]++;
        int t = i;
        while(t != 1 && dis[i]){
            ans[mp[t]]++;
            dis[i]--;
            t = mp[t];
        }
    }
    for(int i = 1;i <= n;++i)
        cout << ans[i] << " ";
    cout << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}