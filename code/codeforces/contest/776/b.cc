#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve()
{
    ll l,r,a;
    cin >> l >> r >> a;
    int ans = 0;
    int ans1 = r / a + r % a;
    int ans2 = 0;
    int b= r / a * a - 1; 
    if(b < l){
        cout<<ans1<<endl;
    }  
    else{
        ans2 = b / a + b % a;
        ans = max(ans1,ans2);
        cout<<max(ans1,ans2)<<endl;
    }

}
 
int main(){
    ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}