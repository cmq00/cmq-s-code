#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
int r,c,ans;
int vis[N][N],mp[N][N];
int nx[] = {0,1,0,-1};
int ny[] = {1,0,-1,0};

int dfs(int x,int y)
{
    if(vis[x][y] != 0) return vis[x][y];
    vis[x][y] = 1;
    int maxx = 0;
    for(int i = 0;i < 4;++i){
        int xx = x + nx[i];
        int yy = y + ny[i];
        if(xx <= r && xx >= 1 && yy <= c && yy >= 1 && mp[xx][yy] < mp[x][y])
            maxx = max(maxx,dfs(xx,yy));
        }
        vis[x][y] += maxx;
        ans = max(ans,vis[x][y]);
        return vis[x][y];
}

int main()
{
    while(~scanf("%d %d",&r,&c)){
        ans = 0;
        memset(vis,0,sizeof(vis));
        
        for(int i = 1;i <= r;++i)
            for(int j = 1;j <= c;++j){
                scanf("%d",&mp[i][j]);
                }
            
        for(int i = 1;i <= r;++i)
            for(int j = 1;j <= c;++j)
                dfs(i,j);
        printf("%d\n",ans);
    }
    return 0;
}

        

