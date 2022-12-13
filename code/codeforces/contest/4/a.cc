#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    int a[55];
    while(t--){
        int n;
        scanf("%d",&n);
        int maxx = -1,minx = 1e9 + 4;
        for(int i = 1;i <= n;++i){
            int x;
            scanf("%d",&x);
            maxx = max(x,maxx);
            minx = min(x,minx);
        }
        printf("%d\n",maxx - minx);
    }
    return 0;
}