#include <bits/stdc++.h>

using namespace std;

string s; int n,k;
int solve()
{
    if(k == 0)
        return 1;
    int len = s.size();
    //cout << len << endl;
    for(int i = 0,j = len - 1;i <= j;++i,--j){
        //cout << s[i] << " " << s[j] << endl;
        if(s[i] != s[j])
            return 2;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        cin >> s;
        int ans = solve();
        cout << ans << endl;
    }
    return 0;
}