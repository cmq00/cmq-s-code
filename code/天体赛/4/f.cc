#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int len = s.size();
    if(len < 6){
        puts("Your password is tai duan le.");
        return ;
    }
    int cha = 0,num = 0,oth = 0,f = 0;
    for(int i = 0;i < len;++i){
        if(('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z'))
            cha++;
        else if('0' <= s[i] && s[i] <= '9')
            num++;
        else if(s[i] == '.')
            oth++;
        else
            f++;
    }
    if(f != 0){
        puts("Your password is tai luan le.");
        return;
    }
    if(num == 0){
        puts("Your password needs shu zi.");
        return ;
    }
    if(cha == 0){
        puts("Your password needs zi mu.");
        return ;
    }
    puts("Your password is wan mei.");
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}