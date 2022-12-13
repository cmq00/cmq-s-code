#include <bits/stdc++.h>

using namespace std;

const int N = 200;
int fa[N],degree[N];

int find(int x)
{
    if(x == fa[x])
        return x;
    else{
        fa[x] = find(fa[x]);
        return fa[x];
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        memset(degree,0,sizeof(degree));
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i = 1;i <= n;++i)
            fa[i] = i;
        while(m--){
            int a,b;
            scanf("%d %d",&a,&b);
            int aa = find(a),bb = find(b);
            if(aa != bb)
                fa[bb] = aa;
            degree[a]++;
            degree[b]++;
        }
        int flag = 0;
        for(int i = 1;i <= n;++i)
            if(fa[i] == i)flag++;
        if(flag != 1)
            printf("No\n");
        else{
            int count = 0;
            for(int i = 1;i <= n;++i)
                if(degree[i] % 2 == 1)count++;
            if(count == 0 || count == 2)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
