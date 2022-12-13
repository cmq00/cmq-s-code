#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    if(n == 1 && s != t){
        puts("NO");
        return ;
    }
    //cout << s <<  " " << t << endl;
    vector<int> v;
    vector<char> v2;
    for(int i = 0;i < s.size();++i){
        if(s[i] == 'b')
            v.push_back(i);
        else
            v2.push_back(s[i]);
    }
    int tot = v.size();
    int num = v2.size();
    for(int i = 0;i < t.size();++i){
        if(t[i] == 'b')
            v.push_back(i);
        else
            v2.push_back(t[i]);
    }
     //cout << "v: " << v.size() << endl;
    int len = v.size() - tot;
    int l = v2.size() - num;
    if(len != tot || l != num){
        puts("NO");
        return ;
    }
    for(int i = 0;i < l;++i){
        if(v2[i] != v2[i + num]){
            puts("NO");
            //cout << "!!" << endl;
            return ;
        }
    }
   // cout << "v: " << v.size() << endl;
    if(v.size() == 0){
        if(s != t)
            puts("NO"); 
        else
            puts("YES");
        return ;
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}