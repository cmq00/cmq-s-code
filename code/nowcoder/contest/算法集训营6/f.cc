#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve()
{
    string s;
    int n,m,sum = 0;;
    cin >> s;
    cin >> m;
    for(int i = 0;i < s.size();++i){
        if(s[i] == '+') sum++;
        else    sum--;
    }
    while(m > 0){
        if(sum >= 0)
            sum -= 2;
        else sum += 2;
        m--;
    }
    cout << abs(sum) << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}