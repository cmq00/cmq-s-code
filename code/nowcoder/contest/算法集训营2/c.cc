#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll x,a,b,cnt = 0;
    cin >> x >> a >> b;
    string s;
    cin >> s;
    int len = s.size();
    for(int i = 0;i < len;++i){
        if(s[i]== '1' && x >= a){
            cnt++;
            x -= a;
        }
        else if(s[i] == '1' && x < a){
            x += b;
        }
        if(s[i] == '0')
            x += b;
    }
    cout << cnt << endl;
    return 0;
}