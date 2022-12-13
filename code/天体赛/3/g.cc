#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    int n,m;
    cin >> n >> m;
    int ans = 0;
    if(n == 0 || m == 0){
        cout << "0" << endl;
        return ;
    }
    while(m != 0){
        //cout << m << endl;
        if(n < m)
            swap(n,m);
        int x = 0;
        if(m != 0)
            x = n / m;
        ans += x;
        n -= m * x;
    }
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