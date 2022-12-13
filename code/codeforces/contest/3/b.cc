#include <bits/stdc++.h>

using namespace std;

const int N = 1e9 + 10;

struct seg
{
    int l,r,val;
};
bool vis[N];

int main()
{
    int t;
    scanf("%d",&t);
    seg a[100004];
    while(t--){
        int n;
        scanf("%d",&n);
        long long ans = 0;
        for(int i = 1;i <= n;++i){
            scanf("%d %d %d",&a[i].l,&a[i].r,&a[i].val);
        }


    }
    return 0;
}