//求有多少个强连通分量
#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 4;

int dfn[N],low[N],num[N],color[N];  //color该点属于哪个连通分量
bool vis[N];
int cnt,colornum;   //colornum有几个连通分量

vector<int> G[N];
stack<int> s;

void tarjan(int x)
{   
    vis[x] = 1;
    s.push(x);
    dfn[x] = low[x] = ++cnt;
    for(int i = 0;i < G[x].size();++i){
        int p = G[x][i];
        if(!dfn[p]){
            tarjan(p);
            low[x] = min(low[x],low[p]);
        }
        else if(vis[p])
            low[x] = min(low[x],dfn[p]);
    }
    if(low[x] == dfn[x]){
        colornum++;
        while(s.top() != x){
            int t = s.top();
            s.pop();
            color[t] = colornum;
            num[colornum]++;
            vis[t] = 0;
        }
        s.pop();
        color[x] = colornum;
        num[colornum]++;
        vis[x] = 0;
    }
}

int main()//https://www.luogu.com.cn/problem/P2863
{
    int n,m; 
    cin >> n >> m;
    for(int i = 1;i <= m;++i){
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    for(int i = 1;i <= n;++i){
        if(!dfn[i])
            tarjan(i);
    }
    int ans = 0;
    for(int i = 1;i <= colornum;++i){
        if(num[i] > 1)
            ans++;
    }
    // // cout << colornum << endl;
    // //  for(int i = 1;i <= n;++i){
    // //     cout << color[i] << " ";
    // // }
    // puts("");
    cout << ans << endl;
    return 0;
}
