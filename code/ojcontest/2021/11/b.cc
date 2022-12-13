#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int tt;
        scanf("%d",&tt);
        tt += 1;
        while(tt--){
            int vis[N];
            memset(vis,0,sizeof(vis));
            int n,m;
            scanf("%d %d",&n,&m);
            if(vis[m] == 0)
                vis[m] = 1;
            if(vis[m] != 0){
                printf("%d\n",m);
                break;
        }
        }
    }
    return 0;
}