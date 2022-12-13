#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 4;
ll n,k;

void solve()
{
    multiset<ll> s;
    int a[N];
    ll ans = 0;
    cin >> n >> k;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
    }
    sort(a + 1,a + 1 + n);
    for(int i = 1;i <= n;++i)
        s.insert(a[i]);
    multiset<ll>::iterator it;
    multiset<ll>::iterator pp;
    for(it = s.begin();it != s.end();){
        pp = s.find(*it * k);
        if(pp != s.end()){
            
            s.erase(pp);
            it = s.erase(it);
        }
        else{
            it++;
            continue;
        }
    }
    cout << s.size() << endl;   
}
 
int main(){
    ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}