#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 1e5 + 4;
int a[N];
bool vis[N];

vector<int> g[N];

void dfs(int x,int p)
{
    if(a[x])
        return ;
    a[x] = p;
    //cout << x << endl;
    for(int i = 0;i < g[x].size();++i){
        dfs(g[x][i],p);
    }
    return ;
}

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= m;++i){
        int u,v;
        cin >> u >> v;
        g[v].push_back(u);
    }
    for(int i = n;i >= 1;--i){
        dfs(i,i);
    }
    for(int i = 1;i <= n;++i){
        cout << a[i] << " ";
    }
    puts("");
    return 0;
}