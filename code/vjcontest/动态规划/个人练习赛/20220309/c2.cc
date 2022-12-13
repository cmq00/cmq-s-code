#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 4;

void solve()
{
    string s;
    cin >> s;
    int c0 = 0,c00 = 0,c1 = 0,c2 = 0;
    int len = s.size();int pos = len;
    for(int i = len - 1;i >= 0;--i){
        if(s[i] == '2'){
            c2++;
            pos = i;
        }
        if(s[i] == '1')
            c1++;
    }
    for(int i = 0;i < pos;++i){
        /*if(s[i] == '0')
            c0++;*/
        if(s[i] == '0')
            cout << s[i];
    }
    for(int i = 1;i <= c1;++i)  
        cout << '1';
    for(int i = pos;i < len;++i){
        if(s[i] != '1')
            cout << s[i];
    }
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