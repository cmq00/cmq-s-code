#include <stdio.h>

#define ll long long

using namespace std;

const int N = 1e5 + 4;
ll n,t,q;

struct Tree
{
    ll l,r,s,color;
}tree[(N << 2) + 4];

void build(ll rt,ll l,ll r)
{
    tree[rt].l = l,tree[rt].r = r,tree[rt].color = tree[rt].s = 1;
    if(tree[rt].l == tree[rt].r)
        return ;
    int mid = (l + r) >> 1;
    build(rt << 1,l,mid);
    build(rt << 1 | 1,mid + 1,r);
    if(tree[rt << 1].color != tree[rt << 1 | 1].color)
        tree[rt].s = tree[rt << 1].s + tree[rt << 1 | 1].s;
}

void update(ll rt,ll l,ll r,ll c)
{
    if(tree[rt].l > r || tree[rt].r < l)
        return ;
    if(tree[rt].l == tree[rt].r){
        tree[rt].color = c;
        return ;
    }
    update(rt << 1,l,r,c);
    update(rt << 1 | 1,l,r,c);
    if(tree[rt << 1].color != tree[rt << 1 | 1].color)
        tree[rt].s = tree[rt << 1].s + tree[rt << 1 | 1].s;
    else
        tree[rt].s = tree[rt << 1].s;
}

ll query(ll i,ll l,ll r)
{
    if(tree[i].l > r || tree[i].r < l)
        return 0;
    if(l <= tree[i].l && tree[i].r <= r)
        return tree[i].s;
    return query(i << 1,l,r) + query(i << 1 | 1,l,r);
}

int main()
{
    scanf("%lld %lld %lld",&n,&t,&q);
    build(1,1,n);
    while(q--){
        char op; ll a,b,c;
        char ch = getchar();
        scanf("%c",&op);
        //printf("op:%c\n",op);
        if(op == 'C'){
            scanf("%lld %lld %lld",&a,&b,&c);
            update(1,a,b,c);
            //printf("ha\n");
        }
        else{
            scanf("%lld %lld",&a,&b);
            printf("%lld\n",query(1,a,b));
        }
    }
    return 0;
}