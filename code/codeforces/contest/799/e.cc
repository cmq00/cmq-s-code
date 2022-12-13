#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 2e5 + 4;

struct Node
{
    int tot;
    int num;
}a[N];

void solve()
{
    ms(a);
    int n;
    cin >> n;
    int s;
    cin >> s;
    int sum = 0;
    vector<int> v;
    v.push_back(0);
    for(int i = 1;i <= n;++i){
        cin >> a[i].num;
        sum += a[i].num;
        if(a[i].num == 1)
            v.push_back(i);
    }
    if(sum < s){
        puts("-1");
        return ;
    }
    if(sum == s){
        puts("0");
        return ;
    }
    int cnt = 0;
    for(int i = n;i >= 1;--i){
        if(a[i].num == 0){
            cnt++;
        }
        else{
            a[i].tot = cnt;
            cnt = 0;
        }
    }
    if(cnt != 0){
        a[0].tot = cnt;
        cnt = 0;
    }
    // for(int i = 1;i <= n;++i){
    //     cout << a[i].tot << " ";
    // }
    // cout << endl;
    // for(int i = 0;i < v.size();++i){
    //     cout << v[i] << " ";
    // }
    // cout << endl;
    int res = -1;
    for(int i = 1,j = s;j < v.size();++i,++j){
        res = max(res,a[v[i - 1]].tot + v[j] - v[i] + 1 + a[v[j]].tot);
    }
    cout << n - res << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}