#include <bits/stdc++.h>

using namespace std;

const int N = 5010;
int n,m,p;
int fa[N];

int find(int x)
{
    if(fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}
void st(int x,int y)
{
    int fx = find(x);
    int fy = find(y);
    if(fx != fy)
        fa[fy] = fa[fx];
}

int main()
{
    scanf("%d %d %d",&n,&m,&p);
    for(int i = 1;i <= n;++i)
        fa[i] = i;
    while(m--){
        int u,v;
        scanf("%d %d",&u,&v);
        st(u,v);
    }
    //printf("fa[6]:%d\n",fa[6]);
    while(p--){
        int ui,vi;
        scanf("%d %d",&ui,&vi);
        if(find(ui) == find(vi))
            printf("Yes\n");
        else
            printf("No\n");
    }
}