#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5 + 4;
ll a[N],b[N],n,m;

struct Tree
{
    ll l,r,s,f,cnt;
}tree[N * 4 + 4];

void build(ll rt,ll l,ll r)
{
    tree[rt].l = l,tree[rt].r = r;
    if(l == r){
        tree[rt].s = a[l];
        tree[rt].id = b[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(rt << 1,l,mid);
    build(rt << 1 | 1,mid + 1,r);
    tree[rt].s = tree[rt << 1].s + tree[rt << 1 | 1].s;
    tree[rt].id = tree[rt << 1].id + tree[rt << 1 | 1].id;
}
//懒标记下放
void pd(ll i)
{
    ll x = i << 1,y = i << 1 | 1;
    tree[x].s += tree[i].f * (tree[x].r - tree[x].l + 1);//修改左子区间和
    tree[y].s += tree[i].f * (tree[y].r - tree[y].l + 1);//修改右区间和
    tree[x].f += tree[i].f;
    tree[y].f += tree[i].f;//修改左右子区间标记
    tree[i].f = 0;//清空大区间标记
}

//区间加
void add(ll i,ll l,ll r,ll v)  
{
    if(tree[i].l > r || tree[i].r < l)//所查询区间与当前区间无重合
        return ;
    if(tree[i].l >= l && tree[i].r <= r){//所查询区间包括当前区间
        tree[i].s += v * (tree[i].r - tree[i].l + 1);
        tree[i].f += v;
        return ;
    }
    pd(i);
    add(i << 1,l,r,v);
    add(i << 1 | 1,l,r,v);
    tree[i].s = tree[i << 1].s + tree[i << 1 | 1].s;
}

ll query(ll i,ll l,ll r)
{
    if(tree[i].l > r || tree[i].r < l)
        return 0;
    if(l <= tree[i].l && tree[i].r <= r)
        return tree[i].s;
    pd(i);
    return query(i << 1,l,r) + query(i << 1 | 1,l,r);
}

int main()
{
    scanf("%lld %lld",&n,&m);
    for(int i = 1;i <= n;++i)
        scanf("%lld",&a[i]);
    for(int i = 1;i <= n;++i)
        scanf("%lld",&b[i]);
    build(1,1,n);
    /*for(int i = 1;i <= 9;++i)
        cout << tree[i].s << " ";
    cout << endl;*/
    while(m--){
        int op,x,y,k;
        scanf("%d",&op);
        if(op == 1){
            scanf("%d %d %d",&x,&y,&k);
            add(1,x,y,k);
        }
        else{
            scanf("%d %d",&x,&y);
            printf("%lld\n",query(1,x,y));
        }
    }
    return 0;
}