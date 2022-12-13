#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a1 = 1;
    for(int i = 1;i <= n;++i){
        ll x;
        cin >> x;
        ll res = a1 + (x - 1) * 3;
        cout << res << endl;
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}