#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int a;
    int b;
};

bool cmp(Node a,Node b)
{
    return a.a < b.a;
}

int main()
{
    Node a[10004],b[10004];
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i = 1;i <= n;++i)
            scanf("%d",&a[i].a);
        for(int i = 1;i <= n;++i)
            scanf("%d",&a[i].b);
        sort(a + 1,a + 1 + n,cmp);
        int ans = 0;
        for(int i = 1;i <= n;++i){
            if(m >= a[i].a)
                m += a[i].b;
        }
        printf("%d\n",m);
    }
    return 0;
}