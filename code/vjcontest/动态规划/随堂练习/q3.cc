#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        int d[10000];
        memset(d,0,sizeof(d));
        scanf("%d %d",&n,&k);
        if(k == 1)
            cout << "1" << endl;
        else{
            d[0] = 0,d[1] = 1,d[2] = 2;
            for(int i = 3;i <= n;++i){
                for(int  j = 1;j <= k;++j){
                    if(i - j >= 0)
                        d[i] = (d[i] % mod + d[i - j] % mod) % mod;
                }
            }
            cout << d[n - 1] << endl;
        }
    }
    return 0;
}