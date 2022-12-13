#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

void solve()
{
    ll N = 100000;
    int a,b,x,y,n;
    cin >> a >> b >> x >> y >> n;
    int ax = a - x;
    int bx = b - y;
    ll res1 = 0,res2 = 0;
    res1 = (long long)(a - min(ax,n)) * (b - min(n - min(ax,n),bx));
    res2 = (long long)(b - min(bx,n)) * (a - min(n - min(bx,n),ax));
    cout << min(res1,res2) << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}