#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

int a[100];
int cnt[100004];

void solve()
{
    int n;
    cin >> n;
    set<int> s;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
        cnt[a[i]]++;
        s.insert(a[i]);
    }
    int len = s.size();
    int x = n - len;
    if(x % 2)
        cout << n - x - 1 << endl;
    else
        cout << n - x << endl;
    //cout << n - n % len << endl;
    // if(s.size() == n){
    //     cout << n << endl;
    //     return ;
    // }
    // int len = s.size();
    // if(n % len == 0){
    //     cout << 2 << endl;
    //     return ;
    // }
    // if(n % len != 0){
    //     cout << 1 << endl;
    //     return ;
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