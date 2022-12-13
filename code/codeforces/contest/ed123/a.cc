#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve()
{
    string s;
    cin >> s;
    int vis[1000];
    memset(vis,0,sizeof(vis));
    int flag = 1;
    for(int i = 0;i < s.size();++i){
        if(s[i] == 'r')
            vis['R' - '0'] = 1;
        if(s[i] == 'g')
            vis['G' - '0'] = 1;
        if(s[i] == 'b')
            vis['B' - '0'] = 1;
        if(s[i] == 'R' && !vis['R' - '0'])
            {flag = 0;break;}
        if(s[i] == 'G' && !vis['G' - '0'])
             {flag = 0;break;}
        if(s[i] == 'B' && !vis['B' - '0'])
            {flag = 0;break;}
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