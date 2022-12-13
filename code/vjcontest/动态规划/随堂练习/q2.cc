#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[150][150];
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i = 1;i <= n;++i)
            for(int j = 1;j <= m;++j)
                scanf("%d",&a[i][j]); 
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= m;++j){
                if(i == 1 && j== 1)
                    continue;
                a[i][j] = max(a[i - 1][j],a[i][j - 1]) + a[i][j];
            }
        }
        printf("%d\n",a[n][m]);
    }
    return 0;

}