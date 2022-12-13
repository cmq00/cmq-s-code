#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

int a[50][50];

void solve()
{
    ms(a);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= m;++j){
            cin >> a[i][j];
        }
    }
    int tot = n + m - 1;
    
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}