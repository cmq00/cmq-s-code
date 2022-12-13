#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 10;

struct Node
{
    int cnt,num;
}a[N];

bool cmp(Node a,Node b)
{
    return a.cnt > b.cnt;
}

void solve()
{
    memset(a,0,sizeof(a));
    int n,k;
    cin >> n >> k;
    for(int i = 1; i <= n;++i){
        int x;
        cin >> x;
        a[x].num = x;
        a[x].cnt++;
    }
    sort(a + 1,a + 1 + n,cmp);
    int t = 0;
    for(int i = 1;i <= n - 1;++i){
        if(t >= k)
            break;
        for(int j = 1;j <= a[i].cnt / a[i + 1].cnt;++j){
            cout << a[i].num << " ";
            t++;
            if(t >= k)
                break;
        }
    }
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