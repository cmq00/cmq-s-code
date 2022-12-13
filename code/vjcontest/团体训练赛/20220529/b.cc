#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

ll gcd(ll n,ll m)
{
    return m ? gcd(m,n % m):n;
}

void solve()
{
    ll x,y,a,b;
    scanf("%lld%lld%lld%lld",&x,&y,&a,&b);
    ll g = gcd(x,y);
    y = y / g;
    x = x / g;
    bool f = 0;
    ll cnt = 0;
    if(x == y){
        printf("2\n");
        return ;
    }
    while(1){
        if(x > y)
            swap(x,y);
        if((y - x) % 2)
            break;
        y = (y - x) / 2;
        if(y < 1) 
            break;
        cnt++;
        //cout << " y: " << y << endl;
        if(x == y && x >= 1){
            f = 1;
            break;
        }
    }
    if(f)
        printf("%lld\n",cnt + 2);
    else
        puts("-1");
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}