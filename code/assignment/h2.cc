
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define inf 0x7fffffff
using namespace std;
const int MAXN = 5e5 + 10;
int dis[MAXN];
int u[MAXN],v[MAXN],w[MAXN];
int first[MAXN],next1[MAXN];
int n,m;
int src,ed;
typedef pair<int,int> pii;
void init()
{
    scanf("%d%d",&n,&m);cin>>src>>ed;
    memset(first,-1,sizeof(first));
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u[i],&v[i],&w[i]);
        next1[i]=first[u[i]];
        first[u[i] ]=i;
        u[i+m]=v[i],v[i+m]=u[i],w[i+m]=w[i];  //无向边，所以加一条反向边
        next1[i+m]=first[u[i+m] ];
        first[u[i+m] ]=i+m;
    }
    
    for(int i=1;i<=n;i++) dis[i]= (i==src? 0:inf);//不要把dis[i]初始化成源点到各点的直接距离，否则会有点没入队。
}
void dijkstra()
{
    priority_queue<pii,vector<pii>,greater<pii> >que;
    que.push(pii(0,src));
    while(!que.empty()){
        pii tmp=que.top();
        que.pop();
        int x = tmp.second;
        if(tmp.first!=dis[x]) continue;  //如果出队的这个元素,他带的dis,和当前的dis不相同，证明这个结点是被处理过的已确定了最短路，
        for(int e=first[x];e!=-1;e=next1[e]){   //这种数组式邻接表的遍历
            if(dis[v[e]]>dis[x]+w[e]){
                 dis[v[e] ]=dis[x]+w[e];
                 que.push(pii(dis[v[e] ],v[e]));
            }
        }
    }
 
}
int main()
{
 //   freopen("1.in","r",stdin);
    
        init();
        dijkstra();
        if(dis[ed]==inf) cout<<"-1"<<endl;
        else cout<<dis[ed]<<endl;
        for(int i=1;i<=n;i++) printf("%d ",dis[i]);//输出dist数组各个值
        putchar('\n');
    
}