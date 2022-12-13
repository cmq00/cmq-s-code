#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 1e5 + 4;
int a[N];
int b[N];

void solve()
{
    int n,m,x;
    cin >> n >> m >> x;
    int ans = 0;
    for(int i = 1;i <= n;++i){
        int xx;
        cin >> xx;
        if(xx >= x)
            ans++;
    }
    for(int i = 1;i <= m;++i){
        int xx;
        cin >> xx;
        if(xx <= x)
            ans++;
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