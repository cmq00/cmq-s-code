#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int fa[N];

int find(int k){//路径压缩！！
    if(fa[k]==k)return k;
    return fa[k]=find(fa[k]);
}

/*void st(int x,int y)
{
    int fx = find(x);
    int fy = find(y);
    if(fx != fy)
        fa[fy] = fa[fx];
}*/

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i <= n;++i)
        fa[i] = i;
    while(m--){
        int op,a,b;
        scanf("%d %d %d",&op,&a,&b);
        if(op == 1)
            fa[find(a)] = find(b);
        else{
            if(find(a) == find(b))
                printf("Y\n");
            else
                printf("N\n");
        }
    }
    return 0;
}