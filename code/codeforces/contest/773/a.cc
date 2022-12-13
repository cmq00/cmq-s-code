#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve()
{
    ll x1,y1,x2,y2,x3,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    ll ans = 0;
    ll maxx = max(y1,max(y2,y3));
    if(y1 == y2 && (y1 != 0 || y2 != 0) && y1 == maxx)
        ans += abs(x1 - x2);
    if(y1 == y3 && (y1 != 0 || y3 != 0) && y1 == maxx)
        ans += abs(x1 - x3);
    if(y2 == y3 && (y3 != 0 || y2 != 0) && y2 == maxx)
        ans += abs(x2 - x3);
    cout << ans << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}