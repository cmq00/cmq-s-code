#include <cstdio>
#include <algorithm>
#include <iostream>
#define ll long long

using namespace std;

int main()
{
    int t,inf = 0x3f3f3f3f;
    cin >> t;
    ll a[100010],sum,s;
    while(t--){
        int n,ans,st,en;
        ans = inf;
        cin >> n >> s;
        for(int i = 0;i < n;++i)
            cin >> a[i];
        //cout << "n:" << n << "s:" << s << endl;
        sum = 0;
        st  = en = 0;
        while(1){
            while(sum < s && en < n){
                sum += a[en++];
                //cout << "en:" << en << " " << "st:" << st << endl; 
            }
            if(sum < s)
                break;
            ans = min(ans,en - st);
            sum -= a[st++];
        }
        if(ans == inf) ans = 0;
        cout << ans << endl;
    }
    return 0;
}
