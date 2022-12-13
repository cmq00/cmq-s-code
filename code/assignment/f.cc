#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;
int n,m;
char mp[N][N];
int vis[N][N];
int step[N][N];
int nx[] = {0,1,0,-1};
int ny[] = {1,0,-1,0};

struct Point
{
    int x,y;
};
    queue<Point> q;

int bfs(Point p)
{
    Point head,next;
    q.push(p);
    step[p.x][p.y] = 0;
    vis[p.x][p.y] = 1;
    while(!q.empty()){
        head.x = q.front().x;
        head.y = q.front().y;
        q.pop();

        for(int i = 0;i < 4;++i){
            next.x = head.x + nx[i];
            next.y = head.y + ny[i];
            if(next.x <= n && next.x >= 1 && next.y >= 1 && next.y <= m && !vis[next.x][next.y] && mp[next.x][next.y] == '.'){
            vis[next.x][next.y] = 1;
            step[next.x][next.y] = step[head.x][head.y] + 1;
            q.push(next);
            }
            if((next.x == 1 || next.x == n || next.y == 1 || next.y == m) && mp[next.x][next.y] == '.')
            //if(next.x == 3 && next.y == 2)
                return step[next.x][next.y];
                //return 22;
        }
    }
    return -1;
}

int main()
{
    int t;
    Point p;
    scanf("%d",&t);
    while(t--){
        while(!q.empty())
            q.pop();
        memset(vis,0,sizeof(vis));
        memset(step,0,sizeof(step));

        scanf("%d %d %d %d",&n,&m,&p.x,&p.y);
        //char pp = getchar();
        for(int i = 1;i <= n;++i)
            for(int j = 1;j <= m;++j)
                cin >> mp[i][j];
        if(p.x == 1 || p.x == n || p.y == 1 || p.y == m)
            printf("0\n");
        else
            printf("%d\n",bfs(p));
    }
    return 0;
}
