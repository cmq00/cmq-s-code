#include <bits/stdc++.h>

using namespace std;

const int N = 50010;
struct Node
{
    int pre,re;
}p[N];

int find(int x)
{
    int t;
    if(x == p[x].pre)
        return x;
    t = p[x].pre;
    p[x].pre = find(t);
    p[x].re = (p[x].re + p[t].re) % 3;
    return p[x].pre;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    
    for(int i = 1;i <= n;++i){
        p[i].pre = i;
        p[i].re = 0;
    }

    int ans = 0;
    
    for(int i = 1;i <= m;++i){
        int op,a,b;
        scanf("%d %d %d",&op,&a,&b);
        if(a > n || b > n){ans++;   continue;}
        if(op == 2 && a == b){ans++;    continue;}
        int root1 = find(a);
        int root2 = find(b);
        if(root1 != root2){
            p[root2].pre = root1;
            p[root2].re = ((3 + op - 1 + p[a].re - p[b].re)) % 3;
        }
        else{
            if(op == 1 && p[a].re != p[b].re){ans++;    continue;}
            else if(op == 2 && (3 - p[a].re + p[b].re) % 3 != op - 1){ans++;    continue;}
        }
    }
    printf("%d\n",ans);
    return 0;
}