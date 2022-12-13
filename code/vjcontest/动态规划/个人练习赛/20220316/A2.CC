#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve()
{
    stack<char> s;
    string ss;
    cin >> ss;
    int len = ss.size();
    int cnt = 0;
    for(int i = 0;i < len;++i){
        if(!s.empty() && ss[i] == s.top()){
            s.pop();
            cnt++;
        }
        else{
            s.push(ss[i]);
        }
    }
    //cout << cnt << endl;
    if(cnt % 2 == 0)
        puts("NO");
    else
        puts("YES");
}
 
int main(){
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}