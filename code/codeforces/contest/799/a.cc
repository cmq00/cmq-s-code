#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

void solve()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int cnt = 0;
    if(b > a)
        cnt++;
    if(c > a)
        cnt++;
    if(d > a)
        cnt++;
    cout << cnt << endl;

}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}