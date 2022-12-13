#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n > 2 || s == "11" || s == "00")
        puts("No");
    else
        puts("Yes");
}
 
int main(){
    ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}