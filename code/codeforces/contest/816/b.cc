#include <cstdio>
#include <iostream>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

void solve()
{
    ll n,k,b,s;
    ll t1 = k * (b + 1) - 1;
    if(s < t1){
        puts("-1");
        return ;
    }
    ll t2 = s - t1;
    ll t3 = t2 / (n - 1);
    if(t3 >= k){
        puts("-1");
        return ;
    }
    ll x = t1 - t3 * (n - 2);
    if(x < k){
        for(int i = 1;i <= n - 2;++i){
            cout << t3 << " ";
        }
        cout << x << " " << t1 << endl;
    }
    else{
        int xx = x - k - 1;
        if(t3 * (n - 2) < k * (n - 2)){
            for(int i = 1;i <= n - 2;++i){
                cout << t3 + xx / (n - 2) << " ";
            }
            cout << t3 + xx -  xx / (n - 2) << " " << x - xx << " " << t1 << endl;
        }
        else{
            puts("-1");
            return ;
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