#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 2e3 + 4;
int a[N],b[N];
ll sum;

void solve()
{
    int n,m,x;
    cin >> n >> m;
    ll c[n + 4][m + 4];
    for(int i = 1;i <= n;++i){
        cin >> a[i];
    }
    for(int i = 1;i <= m;++i){
        cin >> b[i];
    }
    cin >> x;
    for(int j = 1;j <= m;++j){
        for(int i = 1;i <= n;++i){
            c[j][i] = a[i] * b[j];
        }
    }
    // for(int i = 1;i <= m;++i){
    //     for(int j = 1;j <= n;++j){
    //         cout << c[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}