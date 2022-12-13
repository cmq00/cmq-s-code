#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int len = s.size();
    if(len == 6){
        for(int i = 0;i <= 3;++i){
            cout << s[i];
        }
        cout << "-";
        for(int i = 4;i < len;++i){
            cout << s[i];
        }
        cout << endl;
        return ;
    }
    int y;
    y = (s[0] - '0') * 10 + s[1] - '0';
    if(y < 22){
        cout << "20";
    }
    else
        cout << "19";
    cout << s[0] << s[1] << "-" << s[2] << s[3];
    cout << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}