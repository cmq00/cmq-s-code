#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 4;
int fa[N],cnt[N],vis[N];

struct Tree
{
    int u,v;
}tree[N];

bool cmp(Tree a,Tree b)
{
    if(a.u == b.u)
        return a.v < b.v;
    return a.u < b.u;
}
void solve()
{
    memset(cnt,0,sizeof(cnt));
    memset(vis,0,sizeof(vis));
    int n,k;
    cin >> n >> k;
    vector<int> v;
    for(int i = 1;i <= n - 1;++i){
        cin >> tree[i].u >> tree[i].v;
        fa[i] = i;
    }
    sort(tree + 1,tree + n,cmp);
    int t = tree[1].u;
    //v.push_back(t);
    //printf("t:%d\n",t);
    for(int i = 1;i <= n - 1;++i){
        cnt[tree[i].u]++;
        cnt[tree[i].v]++;
        //printf("tree[%d].u :%d\n",i,tree[i].u);
        if(tree[i].u == t)
            v.push_back(tree[i].v);
        else{
            fa[tree[i].v] = fa[tree[i].u];
        }
    }
    for(int i = 1;i <= n;++i){
        if(cnt[i] > k){
            vis[fa[i]]++;
        }
    }

    /*for(int i = 0;i < v.size();++i)
        cout << v[i] << " ";
    cout << endl;* /
\dse
d
    int ans = 0;
    for(int i = 0;i < v.size();++i){
        if(vis[v[i]])
            ans++;
    }
    //cout << cnt[t] << endl;
    if(cnt[t] - ans > k)
        ans += cnt[t] - k;
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