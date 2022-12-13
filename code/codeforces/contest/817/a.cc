#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ss = "Tmiur";
    sort(s.begin(),s.end());
    sort(ss.begin(),ss.end());
    if(s == ss)
        puts("YES");
    else
        puts("NO");
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}