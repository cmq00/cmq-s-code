#include <bits/stdc++.h>

using namespace std;

const int N = 40010;

int fa[N],dx[N],dy[N];

int find(int x)
{
    if(x == fa[x])
        return x;
    else{
        int p = find(fa[x]);

        dx[x] += dx[fa[x]];
        dy[x] += dy[fa[x]];
        return fa[x] = p;
    }
}

int main()
{
    int n,m;
    while(~scanf("%d %d",&n,&m)){
        char op[10],dir[10];
        int u,v,x,y,d;
        for(int i = 0;i <= n;++i){
            fa[i] = i;
            dx[i] = dy[i] = 0;
        }
        while(m--){
            scanf("%s",op);
            if(op[0] == 'A'){
                //cout << op << endl;
                scanf("%d %d %d %s",&u,&v,&d,dir);
                if(dir[0] == 'U')  x = d,y = 0;
                else if(dir[0] == 'D') x = -d,y = 0;
                else if(dir[0] == 'R') x = 0,y = d;
                else if(dir[0] == 'L') x = 0,y = -d;
                int U = find(u),V = find(v);
                if(U != V){
                    fa[U] = V;
                    dx[U] = -dx[u] + dx[v] + x;
                    dy[U] = -dy[u] + dy[v] + y;
                }
                
            }
            else{
                scanf("%d %d",&u,&v);
                int xx = find(u),yy = find(v);
                if(find(u) != find(v))
                    printf("-1\n");
                else if(find(u) == find(v))
                    printf("%d\n", abs(dx[u] - dx[v]) + abs(dy[u] - dy[v]));
            }
        }
    }
    return 0;
}