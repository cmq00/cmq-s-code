#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 1e6 + 4;

int a[N];

int fun(int x)
{
    if(x <= N)
        return a[x];
    if(x > N)
        return (fun(x - 1) % mod + fun(x - 3) % mod) % mod;
    return 1;
}

int main()
{
    a[0] = 0,a[1] = 1,a[2] = 2,a[3] = 3;
    for(int i = 4;i <= N;++i)
        a[i] = (a[i - 1] % mod + a[i - 3] % mod) % mod;
    int n;
    scanf("%d",&n);
    printf("%d\n",a[n]);
    return 0;
}