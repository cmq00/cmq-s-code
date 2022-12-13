#include <bits/stdc++.h>

using namespace std;

const int N = 5010;
const int inf = 0x3f3f3f;
bool vis[N][N];
int mp[N][N];
int n,m,x,y;
int nx[] = {0,1,0,-1};
int ny[] = {1,0,-1,0};

struct Node
{
    int x,y;
};

queue<Node> q;
int bfs(Node po,int mid)
{
    Node hd,nt;
    q.push(po);
    vis[po.x][po.y] = 1;
    while(!q.empty()){
        hd = q.front();
        q.pop();
        for(int i = 0;i <= 3;++i){
            nt.x = hd.x + nx[i];
            nt.y = hd.y + ny[i];
           //printf("**(%d,%d)\n",nt.x,nt.y);
            if(nt.x >= 1 && nt.x <= n && nt.y >= 1 && nt.y <= m && !vis[nt.x][nt.y] && mp[nt.x][nt.y] <= mid){
                vis[nt.x][nt.y] = 1;//printf("(%d,%d)\n",nt.x,nt.y);
                q.push(nt);
                if(nt.x == 1 || nt.x == n || nt.y == 1 || nt.y == m)
                    {return 1;}
            }
        }
    }
    return 0;
}

int main()
{
    int t;
    scanf("%d",&t);

    while(t--){
        while(!q.empty())
            q.pop();
        memset(vis,0,sizeof(vis));
        Node po;
        scanf("%d %d %d %d",&n,&m,&po.x,&po.y);
        int maxx = -inf,minx = inf;
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= m;++j){
                scanf("%d",&mp[i][j]);
                maxx = max(mp[i][j],maxx);
                minx = min(mp[i][j],minx);
            }
        }
        /*for(int i = 1;i <= n;++i){
            for(int j = 1;j <= m;++j)
                printf("%d ",mp[i][j]);
            printf("\n");
        }*/    
        int mid,l = minx,r = maxx;int ans;
        while(l < r){
            while(!q.empty())
                q.pop();
            memset(vis,0,sizeof(vis));
            mid = (l + r) >> 1;
            //printf("l:%d mid:%d r:%d\n",l,mid,r);
            if(bfs(po,mid)) {r = mid;ans = r;}
            else    l = mid + 1;
        }
        //printf("l:%d mid:%d r:%d\n",l,mid,r);
        printf("%d\n",ans);
    }
    return 0;
}