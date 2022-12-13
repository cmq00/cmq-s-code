#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 10;
const int inf = 0x3f3f3f;

int u[N],v[N],w[N],first[N],nt[N],dis[N];
int n,m,s,t;
typedef pair<int,int> p;

void dij()
{
    priority_queue<p,vector<p>,greater<p> >q;
    q.push(p(0,s));
    while(!q.empty()){
        p t = q.top();
        q.pop();
        int x = t.second;
        if(t.first != dis[x]) continue;
        for(int i = first[x];i != -1;i = nt[i]){
            if(dis[v[i]] > dis[x] + w[i]){
                dis[v[i]] = dis[x] + w[i];
                q.push(p(dis[v[i]],v[i]));
            }
        }
    }
}

int main()
{
    cout << inf << endl;
    
    scanf("%d %d",&n,&m);
    for(int i = 1;i <= n - 1;++i){
        scanf("%d %d %d",&u[i],&v[i],&w[i]);
        nt[i] = first[u[i]];
        first[u[i]] = i;
    }
    while(m--){
        memset(first,-1,sizeof(first));
        scanf("%d %d",&s,&t);
        for(int i = 1;i <= n;++i)
            dis[i] = (i == s? 0:inf);
            dij();
            for(int i = 1;i <= n;++i) printf("%d ",dis[i]); cout << endl;
            printf("%d\n",dis[t]);
    }
    return 0;
    
}