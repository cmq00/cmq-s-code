#include <bits/stdc++.h>

using namespace std;

int mp[12][12],vis[12][12],sum[12][12];
int nx[] = {0,1};
int ny[] = {1,0};
int ans[10000],n,ct;

void dfs(int x,int y)
{
    for(int i = 0;i < 2;++i){
        int xx = x + nx[i];
        int yy = y + ny[i];
        if(xx <= n && x >= 1 && yy <= n && yy >= 1 && !vis[xx][yy]){
            printf("xx:%d yy:%d\n",xx,yy);
            vis[xx][yy] = 1;
            sum[xx][yy] += mp[x][y];
            if(xx == n && yy == n)
                ans[ct++] = sum[xx][yy];
            dfs(xx,yy);
        }
    }
}

int main()
{
    scanf("%d",&n);
    memset(mp,0,sizeof(mp));
    while(1){
        int x,y,num;
        scanf("%d %d %d",&x,&y,&num);
        mp[x][y] = num;
        if(x == 0 && y ==0 && num == 0) break;
    }
    dfs(1,1);
    sort(ans,ans + ct);
    printf("ct: %d\n",ct);
    for(int i = 0;i < ct;++i)
        printf("%d ",ans[i]);
    printf("\n");
    printf("%d\n",ans[ct - 1] + ans[ct - 2]);
    return 0;
}