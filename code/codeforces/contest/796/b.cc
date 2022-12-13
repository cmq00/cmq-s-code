#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 2e5 + 4;
int a[N];

int lowbit(int x)
{
    return x & (-x);
}

void solve()
{
    int n;
    cin >> n;
    int e = 0;
    int o = 0;
    ll sum = 0;
    int x = 1000000004;
    ll num = 0;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
        if(a[i] % 2 == 0){
            e++;
            if(lowbit(a[i]) <= x){
                x = lowbit(a[i]);
                num = a[i];
            }
        }
        else    
            o++;
    }
    int cnt = 0;
    while(num){
        int x = num & 1;
        if(x == 1)
            break;
        cnt++;
        num >>= 1;
    }
    if(e == 0){
        puts("0");
        return ;
    }
    if(o != 0){
        cout << min(e,cnt + e - 1) << endl;
        return ;
    }
    cout << cnt + e - 1 << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}