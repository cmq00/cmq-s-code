#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 1e5 + 4;
int n1[N],n0[N];

void solve()
{
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int len = s.size();
    ll ans = 0;
    bool f = 1;
    for(int i = 1;i < len;++i){
        ans += (s[i] - '0')  + (s[i - 1] - '0') * 10;
        if(s[i] == '1' && s[i - 1] == '1'){
            f = 0;
        }
    }
    if(f){
        cout << ans << endl;
        return ;
    }
    for(int i = 1;i < len,k;++i){
        if(s[i] == '1' && s[i - 1]){
            
        }
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}