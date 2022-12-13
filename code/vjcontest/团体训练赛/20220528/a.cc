#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

void solve()
{
    int a,b;
    cin >> a >> b;
    int ans = 0;
    if(a == b){
        cout << '0' << endl;
        return ;
    }
    if(a < b){
            int t = (b - a);
            if(t % 2)
                ans = 1;
            else{
                if((t / 2) % 2)
                    ans = 2;
                else
                    ans = 3;
            }
    }
    else{
         int t = (a - b);
            if(!(t % 2))
                ans = 1;
            else{
                ans = 2;
            }               
    }
    cout << ans << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}