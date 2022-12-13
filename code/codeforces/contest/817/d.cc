#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 2e5 + 4;
ll ans[N];

struct Node
{
    ll l,r;
}a[N];

bool cmp(Node x,Node y)
{
    return (x.r - x.l) > (y.r - y.l);
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll res = 0;
    for(int i = 0;i < s.size();++i){
        if(s[i] == 'L'){
            res += i;
            a[i].l = i;
            a[i].r = n - i - 1;
        }
        else{
            res += n - i - 1;
            a[i].l = n - i - 1;
            a[i].r = i;
        }
    }
    sort(a,a + n,cmp);
    for(int i = 0;i < n;++i){
        if(a[i].r - a[i].l > 0){
            res += a[i].r - a[i].l;
            cout << res << " ";
        }
        else
            cout << res << " ";
    }
    puts("");
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}