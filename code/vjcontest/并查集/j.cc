#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
const int maxn = 1e4 ;
typedef long long LL;
using namespace std;
typedef pair<int,int>P;
 
struct edge{
    int to,cost;
};
int n,m;
vector<edge>G[maxn];
int d[maxn];
void dijk(int s){
    priority_queue<P,vector<P>,greater<P> >q;
    memset(d,INF,sizeof(d));
    d[s]=0;
    q.push(P{0,s});
    while (!q.empty()){
        P p=q.top();
        q.pop();
        int v=p.second;
        if (d[v]<p.first) continue;
        for (int i=0;i<G[v].size();i++){
            edge e=G[v][i];
            if (d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                q.push(P{d[e.to],e.to});
            }
        }
    }
}
int main(){
    while(~scanf ("%d%d",&n,&m)){
        for (int i=0;i<maxn;i++) G[i].clear();
        for (int i=0;i<m;i++){
            int u,v,cost;
            scanf ("%d%d%d",&u,&v,&cost);
            G[u].push_back(edge{v,cost});
            G[v].push_back(edge{u,cost});
        }
        dijk(1);
        int ans=d[n];
        if (ans==INF) printf ("-1\n");
        else printf ("%d\n",ans);
    }
    return 0;
}