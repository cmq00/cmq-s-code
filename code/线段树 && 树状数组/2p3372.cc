#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5 + 4;
ll n,m,a[N];

struct Tree
{
    ll l,r,s,f;
}tree[(N << 2) + 4];

void build(ll rt,ll l,ll r)
{
    tree[rt].l = l,tree[rt].r = r;
    if(tree[rt].l == tree[rt].r){
        tree[rt].s = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1,l,mid);
    build(rt << 1 | 1,mid + 1,r);
    tree[rt].s = tree[rt << 1].s + tree[rt << 1 | 1].s;
}

void pd(ll rt){
    ll x = rt << 1,y = rt << 1 | 1;
    tree[x].s += tree[rt].f * (tree[x].r - tree[x].l + 1);
    tree[y].s += tree[rt].f * (tree[y].r - tree[y].l + 1);
    tree[x].f += tree[rt].f;
    tree[y].f += tree[rt].f;
    tree[rt].f = 0;
}

void add(ll rt,ll l,ll r,ll v)
{
    if(tree[rt].l > r || tree[rt].r < l)
        return ;
    if(tree[rt].l >= l && tree[rt].r <= r){
        tree[rt].s += v * (tree[rt].r - tree[rt].l + 1);
        tree[rt].f += v;
        return ;
    }
    pd(rt);
    add(rt << 1,l,r,v);
    add(rt << 1 | 1,l,r,v);
    tree[rt].s = tree[rt << 1].s + tree[rt << 1 | 1].s;   
}

ll query(ll rt,ll l,ll r)
{
    if(tree[rt].l > r || tree[rt].r < l)
        return 0;
    if(tree[rt].l >= l && tree[rt].r <= r)
        return tree[rt].s;
    pd(rt);
    return query(rt << 1,l,r) + query(rt << 1 | 1,l,r);
}

int main()
{
    scanf("%lld %lld",&n,&m);
    for(int i = 1;i <= n;++i)
        scanf("%lld",&a[i]);
    build(1,1,n);
    while(m--){
        ll op,x,y,k;
        scanf("%lld",&op);
        if(op == 1){
            scanf("%lld %lld %lld",&x,&y,&k);
            add(1,x,y,k);
        }
        else{
            scanf("%lld %lld",&x,&y);
            printf("%lld\n",query(1,x,y));
        }
    }
    return 0;
}
