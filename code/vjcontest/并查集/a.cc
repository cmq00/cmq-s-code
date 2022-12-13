#include <bits/stdc++.h>

using namespace std;

const int N = 50010;
int fa[N];

int find(int x)
{
    if(x == fa[x])
        return x;
    if(fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}

/*void st(int x,int y)
{
    int fx = find(x);
    int fy = find(y);
    if(fx != fy)
        fa[fy] = fx;
}*/
int main()
{
    int n,m,u,v,i,j,sum;
    scanf("%d %d",&n,&m);
        for(i = 0;i <= n;++i)
            fa[i] = i;
        while(m--){
            scanf("%d %d",&u,&v);
            if(find(u) != find(v))
                fa[find(v)] = find(u);
        }
        sum = 0;
        //int f0 = find(0);
        //cout << "f0: " << f0 << endl;
        for(i = 0;i <n;++i){
            if(find(i) == find(0))
            sum++;
        }
        printf("%d\n",sum);
    return 0;
}