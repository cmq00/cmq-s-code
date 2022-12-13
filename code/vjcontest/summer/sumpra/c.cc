#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

int vis[1100004];

void solve()
{
    string s;
    cin >> s;
    int len = s.size();
    // stack<char> st;
    // stack<int> pos;
    // for(int i = 0;i < len;++i){
    //     if(st.empty()){
    //         st.push(s[i]);
    //         pos.push(i);
    //     }
    //     else if(!st.empty()){
    //         if(st.top() == '(' && s[i] == ')'){
    //             st.pop();
    //             pos.pop();
    //             continue;
    //         }
    //         else if(st.top() != '(' || (st.top() == '(' && s[i] != ')')){
    //             st.push(s[i]);
    //             pos.push(i);
    //         }   
    //     }
    // }
    // ll ans = 0;
    // int tot = 0;
    // cout << pos.size() << endl;
    // if(pos.empty()){
    //     vector<int> v;
    //     int cnt = 0;
    //     for(int i = 0;i < len;++i){
    //         if(s[i] == '(')
    //             cnt++;
    //         else{
    //             v.push_back(cnt);
    //             cnt = 0;
    //         }
    //     }
    //     ans += v[0];
    //     for(int i = 1;i < v.size();++i){
    //         ans += v[i] * (i + 1);
    //     } 
    //     cout << ans << endl;
    //     return ;
    // }
    // while(!pos.empty()){
    //     b[++tot] = pos.top();
    //     //cout << pos.top() << " ";
    //     pos.pop();
    // }
    // cout << "tot: " << tot << endl;
    // b[tot + 1] = -1,b[0] = len;
    // int j = tot + 1,k = tot;
    
    // for(int i = tot + 1;i >= 0;--i)
    //     cout << b[i] << " ";cout << endl;

    // for(int i = b[j] + 1;i < b[k] && k >= 0;++i){
    //     cout << "!" << endl;
    //     vector<int> v;
    //     int cnt = 0;
    //     if(s[i] == '(')
    //         cnt++;
    //     else{
    //         v.push_back(cnt);
    //         cnt = 0;
    //     }
    //     cout << "v:" << v.size() << endl;
    //     if(!v.empty()){
    //         ans += v[0];
    //         if(v.size() >= 1)
    //             for(int l = 1;l < v.size();++l){
    //                 ans += v[l] * (l + 1);
    //         }
    //     }
    // }
    // cout << ans << endl;
    // ms(vis);
    // while(!pos.empty()){
    //     int x = pos.top();
    //     vis[x] = 1;
    //     pos.pop();
    // }
   
    // bool f = 1;
    // int cnt = 0;
    // int t = 2;
    // ll ans = 0;
    // vector<int> v;
    // for(int i = 0;i < len;++i){
    //     if(vis[i]){
    //         f = 1;
    //         t = 2;
    //         cnt = 0;
    //     }
    //     else{
    //         if(s[i] == '(')
    //             cnt++;
    //         else{
    //             if(f)
    //                 ans += cnt,f = 0;
    //             else{
    //                 if(cnt >= 2)
    //                     ans +=  (cnt - 1) * t + 1;
    //                 else    
    //                     ans += cnt * t;
    //                 //cout << "ans:" << ans << endl;
    //                 if(cnt != 0) t++;
    //             }
    //             cnt = 0;            
    //         }
    //     }
    // }
    
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
} 
