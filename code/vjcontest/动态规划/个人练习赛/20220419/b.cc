#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;


void solve()
{
    int n,m;
    cin >> n >> m;
    ll a[n + 4][m + 4];
    ll sum[n + 4][m + 4];
    ms(sum);
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= m;++j){
            cin >> a[i][j];
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    }
    int t;
    cin >> t;
    while(t--){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum[x2][y2] + sum[x1 - 1][y1 - 1] - sum[x1 - 1][y2] - sum[x2][y1 - 1] << endl;
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