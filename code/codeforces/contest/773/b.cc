#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int N = 1e9 + 4;

void solve()
{
    int n;
    cin >> n;
    set <int> s;
    for(int i = 1;i <= n;++i){
        int x;
        cin >> x;
        s.insert(x);
    }
    int ans = s.size();
    for(int i = 1;i <= ans;++i)
        cout << ans << " "; 
    for(int i = ans + 1;i <= n;++i){
        ans++;
        cout << ans << " ";
    }
    cout << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}