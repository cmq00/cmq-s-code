#include <bits/stdc++.h>
#define ll long long
using namespace std;

int pos[100004];

void solve()
{
    bool vis = 0;
    string s;
    cin >> s;
    int now = 0,k = 0;
    int len = s.size();
    for(int i = 0;i < len;++i){
        if(s[i] - '0' == 2 || s[i] == '0'){
            if(!vis){
                pos[i] = i;
                k = i;
                vis = 1;
            }
            else
                pos[i] = k;
        }
        else if(s[i] == '1'){
            vis = 0;
            k = 0;
        }
    }
    /*for(int i = 1;i <= 10;++i)
        cout << pos[i] << " ";
    cout << endl;*/
    for(int i = 1;i < len;++i){ //cout << i << " "<< now << endl; 

        if(s[i] > s[now] && s[i] < s[now - 1]){
            swap(s[i],s[pos[now - 1]]);
            swap(s[now],s[i]);
            now++;
            pos[now - 1] = pos[now - 2] + 1;
            continue;
        }
       if(s[i] < s[now] && ((s[now] - '0') - (s[i] - '0'))  == 1){
            swap(s[i],s[now]);
            now++;
            continue;
       }
       if(s[now] != s[i])
       {
            if(s[now] == '0' && s[i] == '2')
                pos[i] = pos[now - 1];
             now = i;
       }

    }
    cout << s << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}