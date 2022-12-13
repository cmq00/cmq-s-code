#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 10;

struct Node
{
    int num,cnt;
}a[N];

bool cmp(Node a,Node b)
{
    return a.cnt > b.cnt;
}

//map<int,int> mp;

void solve()
{
    int n,k,tot = 0;
    cin >> n >> k;
    for(int i = 1;i <= n;++i){
        int x;
        cin >> x;
        if(!a[x].cnt)
            tot++;
        //if(!mp[x])
            //mp[x] = i;
        a[x].num = x;
        a[x].cnt++;
    }
    sort(a + 1,a + 1 + n,cmp);
    if(tot == 1){
        for(int i = 1;i <= k;++i)
            cout << a[1].num << " ";
        cout << endl;
        return ;
    }
    //if(k == n)
    int i;int t = 0;
    cout << tot << endl;
    for(int i = 1;i <= tot;++i) 
        cout << a[i].num << " " << a[i].cnt << endl;
    for(i = 1;i <= tot - 1;++i){
        if(t >= k)
            break;
        for(int j = 1;a[i + 1].cnt != 0 && j <= a[i].cnt / a[i + 1].cnt;++j){
            cout << a[i].num << " ";
            t++;
            if(t >= k)
                break;
        }
    }
    if(t < k)
        for(int j = 1;j <= k - t;++j)
            cout << a[tot].num << " ";
    cout << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}