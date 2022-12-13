#include <bits/stdc++.h>

using namespace std;

const int N = 200;

int main()
{   
    int u[N],v[N];
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        memset(u,0,sizeof(u));
        memset(v,0,sizeof(v));
        while(m--){
            int a,b;
            scanf("%d %d",&a,&b);
            u[a]++;
            v[b]++;
        }
        int count = 0;
        for(int i = 0;i <= n;++i){
            if((u[i] + v[i]) % 2 == 1)    
                count++;
        }
        if(count == 0 || count == 2)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}