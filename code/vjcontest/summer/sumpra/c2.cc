#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;
int pos[1100004];
int dp[1100004];

void solve()
{
    string s;
    cin >> s;
    int len = s.size();
    for(int i = 0;i < len;++i){
        pos[i] = -1;
        dp[i] = 0;
    }
    stack<int> st;
    for(int i = 0;i < len;++i){
        if(s[i] == '('){
            st.push(i);
        }
        else{
            if(s[i] == ')'){
                if(!st.empty())
                    pos[st.top()] = i,st.pop();
            }
            else
                st.push(i);
        }
    }
    // for(int i = 0;i < len;++i){
    //     cout << pos[i] << " ";
    // }
    // cout << endl;
    ll ans = 0;
    for(int i = len - 1;i >= 0;--i){
        if(pos[i] == -1)
            continue;
        dp[i] = dp[pos[i] + 1] + 1;
        ans += dp[i];
    }
    cout << ans << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}