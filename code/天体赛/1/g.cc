#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a[1000004];
void solve()
{
    int n;
    cin >> n;
    int ans = 0;int cnt = 0;
    for(int i = 1;i <= 50;++i){
        if(a[i] % n == 0){
            ans = a[i];
            cnt = i;
            break;
        }
    }
    cout << ans << " " << cnt << endl;
}

int main()
{
    a[1] = 1;
    for(int i = 1;i <= 50;i++)
        a[i] = a[i - 1] * 10 + 1;
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}