#include <cstdio>
#include <cmath>

using namespace std;

const int N = 1200;
int fa[N],vis[N][N],flag[N];

int find(int x)
{
    if(x == fa[x])
        return x;
    else
        return fa[x] = find(fa[x]);
}

struct Point
{
    int x,y;
}p[N];

int main()
{
    int n,d;
    scanf("%d %d",&n,&d);
    for(int i = 1;i <= n;++i){
        scanf("%d %d",&p[i].x,&p[i].y);
        fa[i] = i;
    }
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n;++j){
            if( (p[i].x - p[j].x) * (p[i].x - p[j].x)  + (p[i].y - p[j].y) * (p[i].y - p[j].y) <= d * d){
                vis[i][j] = 1;
                vis[j][i] = 1;
            }
        }
    }
    char s[10];
    while(~scanf("%s",s)){
    if(s[0] == 'O'){
        int x;
        scanf("%d",&x);
        flag[x] = 1;
        for(int i = 1;i <= n;++i){
            if(vis[x][i] && flag[i] && i != x){
                fa[find(x)] = find(i);
            }
        }
    }
    else{
        int x,y;
        scanf("%d %d",&x,&y);
        int xx = find(x),yy = find(y);
        if(xx != yy)
            printf("FAIL\n");
        else   
            printf("SUCCESS\n");
    }
    }
    return 0;
}
    
    

