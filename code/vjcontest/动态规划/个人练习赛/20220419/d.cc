#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

int fa[100];
int vis[100];
int a[100];

int find(int x)
{
    if(x == fa[x])
        return x;
    else
        return fa[x] = find(fa[x]);
}

void solve()
{
    int n,m,k;
    cin >> n >> m;
    k = n - 1;
    for(int i = 1;i <= n;++i)
        fa[i] = i;
    while(k--){
        int u,v;
        cin >> u >> v;
        if(u != 1 && v != 1){
            if(fa[find(u)] != fa[find(v)])
                fa[find(v)] = find(u);
        }
    }
    int ans = 0;
    //if(m == 1 && )
    for(int i = 1;i <= m;++i){
        cin >> a[i];
        //cout << 
        if(!vis[fa[a[i]]] && a[i] != 1){
            ans++;
            vis[fa[a[i]]] = 1;
        }
    }
    if(m == 1 && a[1] == 1)
        ans = 1;
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