#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

void solve()
{
    ll n;
    cin >> n;
    if(n % 2 || n < 4){
        puts("-1");
        return ;
    }
    if(n < 6){
        cout << "1" << " " << "1" << endl;
        return ;
    }
    else{
        ll minx = 0,maxx = 0;
        maxx = n / 4;
        minx = n / 6;
        if(n % 6 == 4)
            minx++;
        if(n % 6 < 4)
            minx += ((n % 6) + 6) / 4 - 1;
        cout << minx << " " << maxx << endl;
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