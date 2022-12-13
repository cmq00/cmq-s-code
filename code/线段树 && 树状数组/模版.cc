#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

struct Node
{
    int l,r;
    int date,add;
}tree[N<<2];//4N数组防止越界
int a[N];

//建树
void build(int rt,int l,int r)
{
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].add = 0;
    if(l == r){
        tree[rt].date = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1,l,mid);
    build(rt << 1 | 1,mid + 1,r);
    tree[rt].date = tree[rt << 1].date + tree[rt << 1 | 1].date;
}
//单点更新
void update(int rt,int x,int v)
{
    if(tree[rt].l == tree[rt].r){
        tree[rt].date += v;
        return;
    }
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    if(x <= mid)
        update(rt << 1,x,v);
    else
        update(rt << 1 | 1,x,v);
    tree[rt].date = tree[rt << 1].date + tree[rt << 1 | 1].date;
}

//区间查询
long long query(int l,int r,int rt)
{
    if(tree[rt].l >= l && tree[rt].r <= r)
        return tree[rt].date;
    int mid = (tree[rt].l + tree[rt].r) >> 1; 
    long long ans = 0;
    if(mid >= l)
        ans += query(l,r,rt << 1);
    if(mid < r)
        ans += query(l,r,rt << 1 | 1);
    return ans;
}

int main()
{
    int n,m;
    cin >> n >> m;
    build(1,1,n);
    for(int i = 1;i <= n;++i){
        cin >> a[i];
    }
    while(m--){
        int op,x,v,l,r;
        cin >> op;
        if(op == 2){
            cin >> l >> r;
            cout << query(l,r,1) << endl;
        }
        else{
            cin >> x >> v;
            update(1,x,v);
            for(int i = 1;i <=n;++i)
                cout << a[i] << " ";
            puts("") ;
        }
    }
    return 0;
}