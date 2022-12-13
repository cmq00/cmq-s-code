#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int n,m,a,b,ans;
int mp[N][N];
int vis[N][N];
int nx[] = {0,1,0,-1};
int ny[] = {1,0,-1,0};

void dfs(int x,int y)
{
    for(int i = 0;i < 4;++i){
        int xx = x + nx[i];
        int yy = y + ny[i];
        if(!vis[xx][yy] && mp[xx][yy] <= mp[a][b] && xx >= 1 && xx <= n && yy >= 1 && yy <= m){
            ans++;
            vis[xx][yy] = 1;
            dfs(xx,yy);
        }
    }
}

int main()
{
    while(~scanf("%d %d %d %d",&n,&m,&a,&b)){
memset(vis,0,sizeof(vis));
    ans = 1;
    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= m;++j)
            scanf("%d",&mp[i][j]);

    vis[a][b] = 1;
    dfs(a,b);
    printf("%d\n",ans);
}
    return 0;
}