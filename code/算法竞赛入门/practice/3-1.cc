#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve()
{
    string s;
    cin >> s;
    int len = s.size();
    int score = 0;
    int cnt = 0;
    for(int i = 0;i < len;++i){
        if(s[i] == 'o'){
            cnt++;
            score += cnt;
        }
        else
            cnt = 0;
    }
    cout << score << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}