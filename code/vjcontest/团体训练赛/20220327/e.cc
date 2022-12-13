#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    double ans = 0.33 * (16.0 - 23.0) + 0.11 * (16.0 - 23.0)+ 0.06 * (16.0 - 23.0 )+ 0.30 * (24.0-23.0) + 0.15 * (54.0 - 23.0)+ 0.04 * (80.0 - 23.0)+ 0.01 * (1000.0 - 23.0);
    cout << ans << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}