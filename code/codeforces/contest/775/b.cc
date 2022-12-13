#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int N = 2e5 + 4;
const int inf = 1e9 + 4;
ll a[N];

int solve()
{
    int n;
    cin >> n;
    int flag = 1,maxx = -1,minx = inf;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
        if(a[i] != 0)
            flag = 0;
        if(a[i] > maxx)
            maxx = a[i];
        if(a[i] < minx)
            minx = a[i];
    }
    sort(a + 1,a + 1 + n);
    ll ans = a[n];
    for(int i = n - 1;i >= 1;--i)
        ans -= a[i];
    //cout << o <<  " " << j << endl;
    if(flag == 1)   
        return 0;
    if(ans <= 0)
        return 1;
    else
        return ans;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) cout << solve() << endl;
    return 0;
}