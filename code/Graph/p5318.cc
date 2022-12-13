#include<bits/stdc++.h>

using namespace std;

struct edge
{
    int u,v;
};

bool cmp(edge a,edge b)
{
    if(a.v == b.v)
        return a.u < b.u;
    return a.v < b.v;
}

const int N = 1e5 + 4;
bool visd[N],visb[N];
vector<int> e[N];
vector<edge> s;

void dfs(int x)
{   
    if(!visd[x]){
        visd[x] = 1;
        cout << x << " ";
    }
    for(int i = 0;i < e[x].size();++i){
        int p = s[e[x][i]].v;
        if(!visd[p])
            dfs(p);
    }
}

queue<int> q;

void bfs(int x)
{
    q.push(x);
    visb[x] = 1;
    cout << x << " ";
    while(!q.empty()){
        int fro = q.front();
        for(int i = 0;i < e[fro].size();++i){
            int p = s[e[fro][i]].v;
            if(!visb[p]){
                q.push(p);
                cout << p << " ";
                visb[p] = 1;
            }
        }
        q.pop();
    }
}

int main()//https://www.luogu.com.cn/problem/P5318
{
    int n,m;
    cin >> n >> m;
    for(int i  = 1;i <= m;++i){
        int u,v;
        cin >> u >> v;
        s.push_back((edge){u,v});
    }
    sort(s.begin(),s.end(),cmp);
    for(int i = 0;i < m;++i){
        e[s[i].u].push_back(i);
    }
    dfs(1);
    cout << endl;
    bfs(1);
    cout << endl;
    return 0;
}