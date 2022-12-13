#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 1e5 + 4;
int a[N];

void solve()
{
    int n;
    cin >> n;
    ll sum = 0;
    int cnt = 0;
    int sumo = 0,sume = 0;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
        if(a[i] % 2)
            sumo++;
        else
            sume++;
    }
    int ans = 0;
    if(sumo > sume)
        ans = sume;
    else
        ans = sumo;
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