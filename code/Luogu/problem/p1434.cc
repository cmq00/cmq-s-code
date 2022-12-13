#include <bits/stdc++.h>

using namespace std;

int nx[] = {0,0,1,-1},ny[] = {1,-1,0,0};
int mp[204][204],vis[204][204];
int ans,anss; 
int n,m;

/*struct Point
{
    int x,y;
}p;

queue<Point> q;*/

int dfs(int x,int y)
{
    /*vis[x][y] = 1;

    step[x][y] = 1;
    Point hd,nt;
    p.x = x,p.y = y;
    q.push(p);
    while(!q.empty()){
        hd = q.front();
        q.pop();
        for(int i = 0;i <= 3;++i){
            nt.x = hd.x + nx[i];
            nt.y = hd.y + ny[i];
            if(nt.x <= n && nt.x >= 1 && nt.y >= 1 && nt.y <= m && !vis[nt.x][nt.y] && mp[nt.x][nt.y] < mp[hd.x][hd.y]){
                //vis[nt.x][nt.y] = 1;
                step[nt.x][nt.y] = step[hd.x][hd.y] + 1; 
                q.push(nt);
                //printf("(%d,%d) %d\n",nt.x,nt.y,step[nt.x][nt.y]);
            } 
            if(step[nt.x][nt.y] > ans){
                ans = step[nt.x][nt.y];
                anss = mp[x][y];
            }
        }
    }*/
    if(vis[x][y])
        return vis[x][y];
    vis[x][y] = 1;
    for(int i = 0;i <= 3;++i){
        int xx = x + nx[i];
        int yy = y + ny[i];
        if(xx >= 1 && xx <= n && yy <= m && yy >= 1 && mp[xx][yy] < mp[x][y]){
            dfs(xx,yy);
            vis[x][y] = max(vis[x][y],vis[xx][yy] + 1);
            //int anss = dfs(xx,yy);
        }
    }
   return vis[x][y];
}

int main()
{
   
    scanf("%d %d",&n,&m);
    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= n;++j)
            scanf("%d",&mp[i][j]);
        
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= m;++j){
            //printf("dfs(%d,%d):%d\n",i,j,dfs(i,j));
            ans = max(ans,dfs(i,j));
            //memset(vis,0,sizeof(vis));
        }
    }
    printf("%d\n",ans);
    return 0;

}
