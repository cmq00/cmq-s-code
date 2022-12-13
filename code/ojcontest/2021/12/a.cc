#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 4;
const int mod = 998244353;

int main()
{
    int a[N];
    a[0] = 0,a[1] = a[2] = 1;
    for(int i = 3;i <= N;++i)
        a[i] = (a[i - 1] % mod + a[i - 2] % mod) % mod;
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        printf("%d\n",a[n]);
    }
    return 0;

}