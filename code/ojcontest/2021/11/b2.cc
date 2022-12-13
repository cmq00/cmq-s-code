#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 10;
map<ll,ll> mp;
int vis[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        memset(vis,0,sizeof(vis));
        int n;
        scanf("%d",&n);
        n += 1;
        while(n--){
            int j,k;
            scanf("%d %d",&j,&k);
            mp[j] = k;
        }
        ll xx= 0;
        while(vis[xx] == 0){
                vis[xx] = 1;
                xx = mp[xx];                
        }
        printf("%lld\n",xx);

    }
    return 0;
}