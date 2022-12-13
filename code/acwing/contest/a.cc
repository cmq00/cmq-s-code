#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    if(n == 0)  
        ans = 1;
    while(n){
        int x = n % 16;
        if(x == 0 || x == 4 || x == 6 || x == 9 || x == 10 || x == 13)
            ans += 1;
        if(x == 8 || x == 11)
            ans += 2;
        n /= 16;
    }
    cout << ans << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}