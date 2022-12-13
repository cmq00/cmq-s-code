#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

map<int,int> mp;
int a[20];
int vis[20];

void solve()
{
    int n,m,k;
    cin >> n >> m;
    k = n - 1;
    while(k--){
        int u,v;
        cin >> u >> v;
        if(u == 1 || mp[u] != 0)
            mp[v] = u;  
        else if(v == 1 || mp[v] != 0)
            mp[u] = v;
    }
    for(int i = 1;i <= n;++i)
        cout << mp[i] << endl;
    //return ;
    int ans = 0;
    for(int i = 1;i <= m;++i){
        int x;
        cin >> x;
        if(!vis[x]){
            vis[x] = 1;
            ans++;
            int xx = mp[x];
            while(xx != 1){
                cout << xx << endl;
                if(!vis[xx]){
                    vis[xx] = 1;
                    //ans++;
                }
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}