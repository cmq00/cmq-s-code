#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 1e7 + 4;

int main()
{
    int a[N];
    a[0] = 0,a[1] = 1,a[2] = 2,a[3] = 3;
    for(int i = 4;i <= N;++i)
        a[i] = (a[i - 1] % mod + a[i - 3] % mod) % mod;
    int n;
    scanf("%d",&n);
    printf("%d\n",a[n]);
    return 0;
}