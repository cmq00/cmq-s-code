#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    int n,m;
    cin >> n >> m;
    int ans = 0,cnt = 0;
    if(m % 2)
        ans = 1;
    else 
        ans = 0;
    for(int i = 1;i <= m / 2;++i){
        cnt = n * 2;
        n = cnt;
    }
    cout << ans << " " << cnt << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}