#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

const int N = 1e5 + 4;
int tot[N];

struct Node
{
    int cnt;
    int num;
}a[N];

bool cmp(Node a,Node b)
{
    if(a.cnt == b.cnt)
        return a.num > b.num;
    return a.cnt * a.num > b.cnt * b.num;
}

void solve()
{
    int n;
    cin >> n;
    set<int> s;
    for(int i = 1;i <= n;++i){
        int x;
        cin >> x;
        s.insert(x);
        tot[x]++;
        a[x].num = x;
        a[x].cnt = tot[x];
    }
    int len = s.size();
    sort(a + 1,a + 1 + len,cmp);
    int ans = 0;
    for(int i = 1;i <= len;++i){
        if(tot[a[i].num] > 0){
            ans += a[i].num * a[i].cnt;
            tot[a[i].num - 1] = 0;
            tot[a[i].num + 1] = 0;
        }
    }
    cout << ans << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}