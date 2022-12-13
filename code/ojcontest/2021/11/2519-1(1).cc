#include <bits/stdc++.h>

using namespace std;

const int N = 101;
char mp[N][N];
int n, m;

/*下一步*/
int nx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int ny[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

/*绊脚的士兵*/
int rank_x[8] = {-1, -1, 0, 0, 1, 1, 0, 0};
int rank_y[8] = {0, 0, 1, 1, 0, 0, -1, -1};

/*后后考虑g-3那个版本，将step,与vis合二为一了
且有路径保存
步数应该会小于32237， 用short
*/
short int step[N][N], vis[N][N];

/*地图小于32237, 可用short*/
struct Point
{
    short int x,y;
};


bool check_map(int x, int y)
{
    /*棋盘外*/
    if (x < 0 || x > n || y < 0 || y > m) 
        return false;

    /*原来只有空地和将军才可走*/
    /*爸原先认为象棋可踩对方的子, 没下面二行，不通过*/
    if (mp[x][y] != '.' && mp[x][y] != 'K')
        return false;

    /*已访问*/
    if (vis[x][y])
        return false;

    /*遇到魔法师*/
    for (int _x = 0; _x <= n; _x ++) {
        /*按理，是魔法师同行，同列会被吃，但象棋中可踩魔法师(其实就是象棋中的猪)*/
        /*如可踩对方的子，则下面二行要恢复*/
        /*if (_x == x)
            continue;*/
        if (mp[_x][y] == 'M')
            return false;
    }

    for (int _y = 0; _y <= m; _y ++)
    {
        /*if (_y == y)
            continue;*/
        if (mp[x][_y] == 'M')
            return false;
    }

    return true;

}

bool check_rank(int x, int y)
{
    if (x < 0 || x > n || y < 0 || y > m) 
        return true;

    /*绊脚*/
    if (mp[x][y] == '*')
        return false;

    return true;
}

int bfs(Point &start, Point &end)
{

    queue <Point> q;
    Point next, cur;

    q.push(start);
    step[start.x][start.y] = 0;
    vis[start.x][start.y] = 1;

    while(!q.empty()){
        cur = q.front();
        q.pop();
        for(int i = 0; i < 8; ++i){
            next.x = cur.x + rank_x[i];
            next.y = cur.y + rank_y[i];
            /*检查是否绊脚*/
            if (!check_rank(next.x, next.y))
                continue;

            next.x = cur.x + nx[i];
            next.y = cur.y + ny[i];
            if(!check_map(next.x, next.y))
                continue;

            vis[next.x][next.y] = 1;
            step[next.x][next.y] = step[cur.x][cur.y] + 1;
                        
            q.push(next);
        
            if(next.x == end.x && next.y == end.y)
                return step[next.x][next.y];
        }
    }
    return -1;
}

int main()
{
    int t;
    Point start, end;
    scanf("%d",&t);

    while(t--){
        memset(vis, 0, sizeof(vis));
        /*这里不用初始化*/
        /*memset(step, 0, sizeof(step));*/

        scanf("%d %d",&n, &m);
        start.x = n, start.y = 0;

        for(int i = 0; i <= n; ++i) {
            scanf("%s", mp[i]);
            for (int j = 0; j <= m; ++j) 
                if (mp[i][j] == 'K') {
                    end.x = i, end.y = j;
                }
        }
        printf("%d\n", bfs(start, end));
    }
    return 0;
}

