#include <bits/stdc++.h>

using namespace std;

const int N = 400;
int step[N][N],vis[N][N];
int go[8][2] = {{-2,-1},{-1,-2},{-2,1},{-1,2},{1,2},{1,-2},{2,1},{2,-1}};

struct Point
{
    int x,y;
};

queue<Point> q;
int bfs(Point p,int x2,int y2)
{
    Point head,next;
    q.push(p);
    step[p.x][p.y] = 0;
    vis[p.x][p.y] = 1;
    while(!q.empty()){
        head.x = q.front().x;
        head.y = q.front().y;
        q.pop();
        for(int i = 0;i < 8;++i){
            next.x = head.x + go[i][0];
            next.y = head.y + go[i][1];
        
            if(next.x >= 0 && next.x <= 300 && next.y >= 0 && next.y <= 300 && !vis[next.x][next.y]){
                vis[next.x][next.y] = 1;
                step[next.x][next.y] = step[head.x][head.y] + 1;
                q.push(next);
            }
            if(next.x == x2 && next.y == y2)
                return step[next.x][next.y];
        }
    }
}

int main()
{
    Point p;
    int x1,y1,x2,y2;
    while(~scanf("%d %d %d %d",&p.x,&p.y,&x2,&y2)){
        memset(vis,0,sizeof(vis));
        memset(step,0,sizeof(step));

        while(!q.empty())
            q.pop();

        printf("%d\n",bfs(p,x2,y2));
    }
    return 0;
}