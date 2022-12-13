#include <bits/stdc++.h>
#define inf 0x7fffffff

using namespace std;

const int N = 1e5 + 10;
const int M = 5e5 + 10;
int u[M],v[M],w[M],first[M],nt[M],dis[M];
int n,m,s,t;
typedef pair<int,int> pii;

void init()
{
    scanf("%d %d %d %d",&n,&m,&s,&t);
    memset(first,-1,sizeof(first));

    for(int i = 1;i <= m;++i){
        scanf("%d %d %d",&u[i],&v[i],&w[i]);
        nt[i] = first[u[i]];
        first[u[i]] = i;
        /*u[i+m]=v[i],v[i+m]=u[i],w[i+m]=w[i];
        nt[i+m]=first[u[i+m] ];
        first[u[i+m] ]=i+m;*/
    }
    for(int i = 1;i <= n;++i){
        dis[i] = (i == s? 0:inf);
    }   
}

void dijkstra()
{
    priority_queue<pii,vector<pii>,greater<pii> > q;
    q.push(pii(0,s));
    while(!q.empty()){
        pii t = q.top();
        q.pop();
        int x = t.second;
        if(t.first != dis[x]) continue;
        for(int i = first[x];i != -1;i = nt[i]){
            if(dis[v[i]] > dis[x] + w[i]){
                dis[v[i]] = dis[x] + w[i];
                q.push(pii(dis[v[i]],v[i]));
            }
        }
    }
}

int main()
{
    init();
    dijkstra();
    //for(int i=1;i<=n;i++) printf("%d ",dis[i]);
    printf("%d\n",dis[t]);
    return 0;
}