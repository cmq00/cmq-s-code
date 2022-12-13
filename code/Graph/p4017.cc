#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mod = 80112002;

vector<int> G[5004];
queue<int> q;
int in[5004],out[5004];
ll res[5004];

void bfs()
{
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i = 0;i < G[x].size();++i){
            int p = G[x][i];
            in[p]--;
            res[p] = (res[x] % mod + res[p] % mod) % mod;
            if(in[p] == 0){
                q.push(p);
            }
        }
    }
}

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= m;++i){
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        in[v]++;
        out[u]++;
    }
    for(int i = 1;i <= n;++i){
        if(in[i] == 0){
            res[i] = 1;
            q.push(i);
        }
    }
    bfs();
    ll ans = 0;
    for(int i = 1;i <= n;++i){
        if(!out[i])
            ans = (ans % mod + res[i] % mod) % mod;
    }
    cout << ans << endl;
}