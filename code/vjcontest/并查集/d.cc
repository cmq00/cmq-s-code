#include <cstdio>

using namespace std;

const int N = 50010;
int fa[3 * N];

int find(int x)
{
    if(x == fa[x])
        return x;
    else
        return fa[x] = find(fa[x]);

}

int main()
{
    int n,m,ans = 0;
    scanf("%d %d",&n,&m);
    for(int i = 0;i <= 3 * n;++i){
        fa[i] = i;
    }
    while(m--){
        //cout <<"m: "<< m << endl;
        int op,u,v;
       
        scanf("%d %d %d",&op,&u,&v);
        if(u > n || v > n){ans++;continue;}
        //if(op == 2 && u == v){ans++;continue;}
        if(op == 1){
            if(find(u + n) == find(v) || find(u) == find(v + n)){ans++;continue;}
            else{
                fa[find(u)] = find(v);
                fa[find(u + n)] = find(v + n);
                fa[find(u + n + n)] = find(v + n + n);
            }
        }
        else{
            if(find(u) == find(v) || find(u) == find(v + n))
            {ans++;continue;}
            else{
                fa[find(u + n)] = find(v);
                fa[find(u + n + n)] = find(v + n);
                fa[find(u)] = find(v + n + n);
            }
        }
    }
    printf("%d\n",ans);
    
    return 0;
}