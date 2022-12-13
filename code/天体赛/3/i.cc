#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 200;
int a[N];
int b[N];
int sum[N];

void solve()
{
    memset(sum,0,sizeof(sum));
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
    }
    sort(a + 1,a + 1 + n);
    for(int i = 1;i <= n;++i)
        b[i] = a[i] - a[i - 1];
    sort(b + 1,b + 1 + n);
    int ans = 0;
    for(int i = 1;i <= n;++i){
        sum[i] = b[i] + sum[i - 1];
        b[i] = sum[i];
        ans += b[i];
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