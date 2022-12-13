#include <cstdio>
#include <iostream>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

ll ans[100004];

void solve()
{
    ll n,k,b,s;
    cin >> n >> k >> b >> s;
    if(s < k * b){
        puts("-1");
        //cout << "n1" << endl;
        return ;
    }
    if(s <= k * (b + 1) - 1){
        for(int i = 1;i <= n - 1;++i){
            cout << "0" << " ";
        }
        cout << s << endl;
        return ;
    }   
    ll t = s - (k * (b + 1) - 1);
    if(n == 1){
        //cout << "n2" << endl;
        puts("-1");
        return ;
    }
    if(n - 1 >= t){
        for(int i = 1;i <= t;++i){
            cout << "1" << " ";
        }
        for(int i = t + 1;i <= n - 1;++i){
            cout << "0" << " ";
        }
        cout << k * (b + 1) -  1<< endl;
        return ;
    }
    if(t / (n - 1) >= k){
        puts("-1");
        return ;
    }
    ll cnt = t % (n - 1);
    for(int i = 1;i <= n - 1;++i){
        ans[i] = t / (n - 1);
    }
    for(int i = 1;i <= n - 1;++i){
        if(cnt){
            ans[i] += 1;
            cnt--;
            if(ans[i] >= k){
                puts("-1");
                return ;
            }
        }
    }
    for(int i = 1;i <= n - 1;++i)
        cout << ans[i] << " ";
    cout << k * (b + 1) -  1<< endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}