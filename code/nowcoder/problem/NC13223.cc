#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int main()
{
    ll n;
    scanf("%lld",&n);
    ll ans = 0;
    int a;
    scanf("%d",&a);
    n -= 1;
    ll cont1 = 0,cont2 = 0;
    while(n--){
        int x;
        scanf("%d",&x);
        if(x > a){
            cont1++;
        }
        else
            cont2++;
    }
    while(cont2 > 1){
        cont2 /= 2;
        ans++;
    }
    printf("%lld\n",ans);
    return 0;
}