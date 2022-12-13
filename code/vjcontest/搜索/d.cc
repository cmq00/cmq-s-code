#include <bits/stdc++.h>

using namespace std;

char oil[200][200];
//int vis[200][200];
//int num[104];
int r,c;
int Next[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
//int nx[] = {1,0,-1,0,1,-1,1,-1};
//int ny[] = {0,1,0,-1,1,-1,-1,1};
void dfs(int x,int y)
{
    int i;
    for(i = 0;i < 8;++i){
        int xx = x + Next[i][0];
        int yy = y + Next[i][1];
        //int xx = x + nx[i];
        //int yy = x + ny[i];
        if(xx >= 1 && xx <= r && yy <= c && yy >= 1 && oil[xx][yy] != '*'){
            oil[xx][yy] = '*';
            dfs(xx,yy);
        }
    }
        //printf("k1:%d\n",k1);
}

int main()
{
       while(cin >> r >> c,r||c){ 
       int ans = 0;
        
        //memset(vis,0,sizeof(vis));
        //memset(num,0,sizeof(num));
        
        //char p = getchar();
        for(int i = 1;i <= r;++i)
            for(int j = 1;j <= c;++j)
                cin >> oil[i][j];
        for(int i = 1;i <= r;++i)
            for(int j = 1;j <= c;++j){
                if(oil[i][j] == '@'){
                    oil[i][j] = '*';
                    ans++;
                    dfs(i,j);
                }
            }
        printf("%d\n",ans);
    }
    return 0;
}

