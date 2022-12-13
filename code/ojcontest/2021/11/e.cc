#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
char mp[N][N];
int n,m;
int nx[4][2] = {0,1,1,0,0,-1,-1,0};
int nxx[4][2][2] = {1,1,-1,1,1,1,1,-1,1,-1,-1,-1,-1,1,-1,-1};
int vis[N][N],step[N][N],mage[N][2];

struct Point
{
    int x,y;
};

queue<Point> q;

bool check1(int x,int y)
{
    if(x >= 0 && x <= n && y >= 0 && y <= m && !vis[x][y] && (mp[x][y] == '.' || mp[x][y] == 'K') && mage[x][0] == 0 && mage[y][1] == 0)
        return 1;
    return false;
}
bool check2(int x,int y)
{
    if(x >= 0 && x <= n && y >= 0 && y <= m && mp[x][y] == '.' )
        return 1;
    return false;
}

int bfs(Point p,Point pp)
{
    Point a,aa,aaa;
    q.push(p);
    step[p.x][p.y] = 0;
    vis[p.x][p.y] = 1;
    while(!q.empty()){
        a = q.front();
        q.pop();
        for(int i = 0;i < 4;++i){
            aa.x = a.x + nx[i][0];
            aa.y = a.y + nx[i][1];
            
            if(check2(aa.x,aa.y)){
                //vis[aa.x][aa.y] = 1;
                for(int j = 0;j < 2;++j){
                    aaa.x = aa.x + nxx[i][j][0];
                    aaa.y = aa.y + nxx[i][j][1];

                    if(check1(aaa.x,aaa.y)){
                        vis[aaa.x][aaa.y] = 1;
                        step[aaa.x][aaa.y] = step[a.x][a.y] + 1;
                        q.push(aaa);
                    }
                if(aaa.x == pp.x && aaa.y == pp.y)
                    return step[aaa.x][aaa.y];
                }
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    Point p,pp;
    scanf("%d",&t);
    while(t--){
        while(!q.empty())
            q.pop();
        memset(vis,0,sizeof(vis));
        memset(step,0,sizeof(step));
        memset(mage,0,sizeof(mage));

        scanf("%d %d",&n,&m);
        p.x = n,p.y = 0;

        for(int i = 0;i <= n;++i){
            getchar();
            for(int j = 0;j <= m;++j){
                scanf("%c",&mp[i][j]);
                if(mp[i][j] == 'K')
                    pp.x = i,pp.y = j; 
                if(mp[i][j] == 'M')
                    mage[i][0] = 1,mage[j][1] = 1;
            }
        }
        printf("%d\n",bfs(p,pp));
    }
    return 0;
}

