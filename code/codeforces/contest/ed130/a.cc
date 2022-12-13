#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;


int a[1200];

void solve()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
    }
    ll sum = 0;
    for(int i = 2;i <= n;++i){
        sum += a[i];
    }
    ll ans = 0;
    if(sum + a[1] <= m){
        puts("0");
        return ;
    }
    if(m <= a[1]){
        ans = sum + a[1] - m;
    }
    else{
        ans = sum - (m - a[1]);
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