#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 4;

const int inf = 1e9;
ll a[N];

void solve()
{
    int n;
    cin >> n;
    int maxx = -inf,minx = inf;
    for(int i = 1;i <= n;++i){
        int x;
        cin >> x;
        maxx = max(x,maxx);
        minx = min(x,minx);
    }
    //cout << maxx << " " << minx << endl;
    //cout << maxx - minx << endl;
    ll ans = (maxx - minx) * n;
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