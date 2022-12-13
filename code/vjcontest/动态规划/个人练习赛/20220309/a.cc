#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int solve()
{
    int l,r,d;
    cin >> l >> r >> d;
    if(l  > d)
        return d;
    if(r < d)
        return d;
    if(l <= d && d <= r)
        return ((r / d) + 1) * d;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) cout << solve() << endl; 
    return 0;
}