#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
double a[500];

void prework()
{
    a['C'] = 12.01;
    a['H'] = 1.008;
    a['O'] = 16.00;
    a['N'] = 14.01;
}
void solve()
{
    string s;
    cin >> s;
    int len = s.size();
    double ans = 0;
    for(int i = 0;i < len;++i){
        if(s[i + 1] >= '0' && s[i + 1] <= '9')
            ans += a[s[i]] * (s[i + 1] - '0');
        else
            ans += a[s[i]];
    }
    cout << ans << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    prework();
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}