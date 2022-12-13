#include <queue>
#include <cstdio>

using namespace std;

struct Point
{
    int x,y,pos;

}p;
int maze[5][5];
int vis[5][5];
int x[100],y[100],pre[100],idx;
int nx[] = {0,1,0,-1};
int ny[] = {1,0,-1,0};
queue<Point> q;

void bfs()
{
    
    Point head,next;
    q.push(p);
    int sum = 0;
    vis[p.x][p.y] = 1;
    
    while(!q.empty()){
        head = q.front();
        q.pop();
        if(head.x == 4 && head.y == 4){
            idx = head.pos;
            return ;
        }
        for(int i = 0;i < 4;++i){
            next.x = head.x + nx[i];
            next.y = head.y + ny[i];
            if(next.x >= 0 && next.x < 5 && next.y < 5 && next.y >= 0 && !vis[next.x][next.y] && maze[next.x][next.y] == 0){
                sum++;
                next.pos = sum;
                vis[next.x][next.y] = 1;
                q.push(next);

                x[sum] = next.x,y[sum] = next.y;
                pre[sum] = head.pos;
            
            }
        }
    }
}

void dfs(int idx)
{
    if(idx == 0){
        printf("(%d, %d)\n",x[idx],y[idx]);
        return ;
    }
    dfs(pre[idx]);
    printf("(%d, %d)\n",x[idx],y[idx]);
}

    
int main()
{
    int i,j;
    for(i = 0;i < 5;++i){
        for(j = 0;j < 5;++j){
            scanf("%d ",&maze[i][j]);
        }
    }
    p.x = p.y = p.pos = 0;

    bfs();
    dfs(idx);
    return 0;
}