#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 2e5 + 4;
int a[N];
ll sume[N],sumo[N],sum[N];

void solve()
{
    ms(sume);
    ms(sumo);
    int n;
    cin >> n;
    for(int i = 0;i < n;++i){
        cin >> a[i];
        if(i % 2)
            sumo[i] += sumo[i - 2] + a[i];
        else
            sume[i] = sume[i - 2] + a[i];
    }
    int pos = 0;
    ll ans = 0;
    for(int i = 0;i < n;++i){
        cout << sume[i] << " ";
    }
    cout << endl;
    for(int i = 0;i < n;++i){
        cout << sumo[i] << " ";
    }
    cout << endl;
    for(int i = 0;i < n;++i){
        if(i % 2){
            cout << "i: " << i << " sumo[i]: " << sumo[pos] << endl;
            if(sumo[i] >= sume[i - 1]){
                pos = i;
            }
        }
    }
    cout << "pos: " << pos << endl;
    cout << "sumo[pos]: " << sumo[pos] << endl;
    ans += sumo[pos];
    for(int i = pos;i < n;++i){
        if(i % 2 == 0){
            ans += a[i];
        }
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