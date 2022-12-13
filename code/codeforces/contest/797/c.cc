#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 4;
int a[N];
int b[N];

void solve()
{
    vector<int> ans;
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
    }
    b[0] = 0;
    for(int i = 1;i <= n;++i){
        cin >> b[i];
        if(a[i] >= b[i - 1])
            ans.push_back(b[i] - a[i]);
        else
            ans.push_back(b[i] - b[i - 1]);
    }
    for(int i = 0;i < ans.size();++i)
        cout << ans[i] << " " ;
    cout << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}