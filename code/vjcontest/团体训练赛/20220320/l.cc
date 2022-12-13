#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int len = s.size();
    int pos = 0;
    int i;
    for(i = 1;i < len;++i){
        if(s[i] != s[0]){
            pos = i;
            break;
        }
    }
    if(i == len)
        cout << len - 1 << endl;
    else
        cout << len - pos + len << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}