#include <bits/stdc++.h>

using namespace std;

const int N = 150;
bool vis[N][N];
char mp[N][N];
int n,m,x2,y2;
int nx[] = {1,0,-1,0};
int ny[] = {0,1,0,-1};

struct Point
{
    int x,y;
}p;

queue<Point> q;

bool bfs()
{
    Point hd,nt;
    //p.x = x1;
    //p.y = y1;
    q.push(p);
    while(!q.empty()){
        hd = q.front();
        //cout << hd.x << " " << hd.y << endl;
        q.pop();
        for(int i = 0;i <= 3;++i){
            nt.x = hd.x + nx[i];
            nt.y = hd.y + ny[i];//cout << nt.x << " " << nt.y << endl;
            if(nt.x >= 1 && nt.x <= n && nt.y >= 1 && nt.y <= m && !vis[nt.x][nt.y] && mp[nt.x][nt.y] != 'o'){
                
                vis[nt.x][nt.y] = 1;
                q.push(nt);
            }
            if(nt.x == x2 && nt.y == y2)
                return 1;
        }

    }
    return 0;
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= m;++j){
            cin >> mp[i][j];
            if(mp[i][j] == 'P')
                {p.x = i;p.y = j;}
            if(mp[i][j] == 'X')
                {x2 = i;y2 = j;}
        }
    }
    //cout << p.x << " " << p.y << endl;
    //cout << x2 << " " << y2 << endl;
    vis[p.x][p.y] = 1;
    if(bfs())
        printf("Playftql\n");
    else
        printf("Playftcl\n");
    return 0;
}