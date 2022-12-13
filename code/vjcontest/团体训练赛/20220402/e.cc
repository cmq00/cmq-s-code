#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 4;
int fa[N];

int find(int x)
{
    if(x == fa[x])
        return x;
    if(fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}

void solve()
{
    int n,m,u,v;
    cin >> n >> m;
    for(int i = 1;i <= n;++i)
        fa[i] = i;
    while(m--){
        cin >> u >> v;
        if(find(u) != find(v))
            fa[find(v)] = find(u);
    }
    int ans = 0;
    for(int i = 1;i <= n;++i){
        if(find(i) != find(1))
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}