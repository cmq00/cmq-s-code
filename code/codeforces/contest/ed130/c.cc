#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if(n == 1){
        puts("NO");
        return ;
    }
    string s;
    string t;
    cin >> s >> t;
    vector<char> v1;
    vector<char> v2;
    for(int i = 0;i < s.size();++i){
        if(s[i] != 'b')
            v1.push_back(s[i]);
    }
    for(int i = 0;i < t.size();++i){
        if(t[i] != 'b')
            v2.push_back(t[i]);
    }
    if(v1.size() != v2.size()){
        puts("NO");
        return ;
    }
    for(int i = 0;i < v1.size();++i){
        if(v1[i] != v2[i]){
            puts("NO");
            return ;
        }
    }
    puts("YES");
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}