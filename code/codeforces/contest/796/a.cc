#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

void solve()
{
    ll n;
    cin >> n;
    if(n % 2 == 0){
        int cnt = 0;
        int pos = 0;
        bool f = 1;
        while(n){
            int x = n & 1;
            if(x == 1){
                cnt++;
                f = 0;
            }
            if(f)
                pos++;
            n >>= 1;
        }
        if(cnt >= 2){
            ll ans = pow(2,pos);cout << ans << endl;
        }
        else{
            ll ans = pow(2,pos);cout << ans  + 1 << endl;
        }
    }
    else{
        if(n == 1)
            puts("3");
        else
            puts("1");
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}