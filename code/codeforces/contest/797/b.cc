#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 5e4 + 4;
ll a[N];ll b[N];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
    }
    bool bb = 1;
    for(int i = 1;i <= n;++i){
        cin >> b[i];
        if(b[i] != 0)
            bb = 0;
    }
    if(bb){
        puts("YES");return ;}
    ll f = 0;
    for(int i = 1;i <= n;++i){
        if(b[i] != 0){
            f = a[i] - b[i];
            break;
        }
    }
    bool ff = 1;
    //ll k = -1;
    ll num = 1000000004;
    for(int i = 1;i <= n;++i){
        if(b[i] == 0){
            if(a[i] > f){
                ff = 0;
                break;
            }
            continue;
        }
        num = a[i] - b[i];
        if(num != f || a[i] <= b[i]){
            ff = 0;
            break;
        }
    }
    if(ff)
        puts("YES");
    else
        puts("NO");
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}
