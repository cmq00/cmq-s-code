#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 1e5 + 4;
ll a[N];
ll pos[N];

void solve()
{
    ms(pos);
    int n;
    cin >> n;
    map<int,int> mp;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
        mp[a[i]]++;
        if(a[i] == a[i - 1])
            pos[i] = i;
        else
            pos[i] = 0;
    }
    for(int i = 1;i <= n;++i){
        if(mp[a[i]] < 2){
            puts("-1");
            return ;
        }
    }
    for(int i = 2;i <= n;++i){
        if(pos[i + 1] == 0){
            cout << pos[i] << " ";
            for(int j = pos[i] - mp[a[i]] + 1;j < pos[i];++j)
                cout << j << " ";
        }
    }
    cout << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}