#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e4 + 4;

struct Node
{
    int o,p,sum;
}a[N];

bool cmp(Node a,Node b)
{
    return a.sum > b.sum;
}

void solve()
{
    int n;
    cin >> n;
    int b,c,d;
    map<int,int> mp;
    int maxx = 0;
    for(int i = 1;i <= n;++i){
        scanf("%d-%d %d",&b,&c,&d);
        //cout << b << " " << c << " " << d << endl;
        a[b].sum += d;
        a[b].o = b;
        a[b].p = c;
        maxx = max(maxx,b);
    }
    sort(a + 1,a + 1 + maxx,cmp);
    //for(int i = 1;i <= n;++i)
        //cout << a[i].o << " " << a[i].p << " " << a[i].sum << endl;
    cout << a[1].o << " " << a[1].sum << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}