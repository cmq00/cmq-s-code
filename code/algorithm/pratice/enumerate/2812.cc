#include <bits/stdc++.h>

using namespace std;

#define MAX 5010
int r,c,n,ans = 0;

struct Field
{
    int x,y;
}f[MAX];

bool flag[MAX][MAX];

bool outside(int x1,int y1)
{
    if(x1 <= 1 || y1 <= 1 || x1 > r || y1 > c)
        return 1;
    return 0;
}

bool count(int a,int b)
{
    //printf("a:%d b:%d\n",a,b);
    int k = 2;
    int dx,dy;
    dx = f[b].x - f[a].x,dy = f[b].y - f[a].y;
    //printf("dx:%d,dy:%d  ",dx,dy);
    if(!outside(f[a].x - dx,f[a].y - dy))
        return 0;
    if(f[a].x + ans * dx <= 1 || f[a].x + ans * dx > r)
        return 0;
    if(f[a].y + ans * dy <= 1 || f[a].y + ans * dy > c)
        return 0;
    int sx = f[b].x + dx,sy = f[b].y + dy;
        //printf("sx:%d,sy:%d\n",sx,sy);
    while(!outside(sx,sy)  && flag[sx][sy]){
        ++k;
        //cout << "k:" << k;
        sx += dx;
        sy += dy;
    }
    //cout << endl << endl<<endl;
    if(outside(sx,sy) && k > ans) ans = k;
    //return 1;
}

bool cmp(Field a,Field b)
{
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

int main()
{
    scanf("%d %d %d",&r,&c,&n);
    for(int i = 1;i <= n;++i){
        scanf("%d %d",&f[i].x,&f[i].y);
        flag[f[i].x][f[i].y] = 1;
    }
    
    sort(f + 1,f + n + 1,cmp);
    
    int i,j;
    //for(i = 1;i <= n;++i)
    //cout << i << ":(" <<  f[i].x <<", "<< f[i].y<<")" << "  ";
        //cout << endl;
    for(i = 1;i <= n;++i){
        for(j = i + 1;j <= n;++j){
         //   printf("i:%d j:%d\n",i,j);
            count(i,j);
        }
    }
    if(ans < 3) ans = 0;    
    printf("%d\n",ans);
    return 0;
}



