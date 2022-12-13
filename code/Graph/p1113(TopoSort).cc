#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 4;

int t[N],in[N],f[N];
vector<int> G[N];
queue<int> q;

void bfs()
{
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = 0;i < G[now].size();++i){
            int po = G[now][i];
            in[po]--;
            if(in[po] == 0)
                q.push(po);
            f[po] = max(f[po],f[now] + t[po]);
        }
    }
}

int main()//https://www.luogu.com.cn/problem/P1113
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i){
        int u,v;
        cin >> u;
        cin >> t[i];
        while(cin >> v){
            if(v == 0)
                break;
            G[u].push_back(v);
            in[v]++;
        }
    }
    for(int i = 1;i <= n;++i){
        if(in[i] == 0)
            q.push(i);
            f[i] = t[i];
    }
    bfs();
    int ans = 0;
    for(int i = 1;i <= n;++i){
        ans = max(ans,f[i]);
    }
    cout << ans << endl;
}