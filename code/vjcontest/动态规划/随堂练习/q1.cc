#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int a[150][150];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        //memset(a,0,sizeof(a));
        a[1][1] = 1;
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= m;++j){
                if(i == 1 && j == 1)
                    continue;
                a[i][j] = (a[i - 1][j] % mod + a[i][j - 1] % mod) % mod;
            }
        }
        printf("%d\n",a[n][m]);
    }
    return 0;
}