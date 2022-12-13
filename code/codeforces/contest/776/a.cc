#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve()
{
    string s;
    cin >> s;
    char ch;
    cin >> ch;
    int flag = 0;
    vector<int> v;
    int len = s.size();
    for(int i = 0;i < len;++i){
        if(s[i] == ch)
            v.push_back(i);
    }
    for(int i = 0;i < v.size();++i){
        if(v[i] % 2 == 0 && (len - v[i] - 1) % 2 == 0)
            {//cout << i << endl;
            flag = 1;break;}
    }
    if(flag == 1)
        puts("Yes");
    else
        puts("No");
}
 
int main(){
    ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}