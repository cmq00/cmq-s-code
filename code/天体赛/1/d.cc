#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    int x,y,z;
    cin >> x >> y >> z;
    if(y * y + z * z + x * x == 3 * x * y * z)
        puts("Yes");
    else
        puts("No");
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}