#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll a[100],sum[100];
    a[1] = 1;
    sum[1] = 1;
    for(int i = 2;i <= 55;++i){
        a[i] = a[i - 1] * i;
        sum[i] = sum[i - 1] + a[i];
    }   
    int n;
    scanf("%d",&n);
    printf("%lld\n",sum[n]);
    return 0;
}