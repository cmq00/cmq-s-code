#include <bits/stdc++.h>

using namespace std;

int gcd(int n,int m)
{
    return m ? gcd(m,n % m) : n;
}

int main()
{
    int a[50004];
    int cnt[50004];int vis[50004];
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i <= n;++i)
        scanf("%d",&a[i]);
    while(m--){
        memset(cnt,0,sizeof(cnt));
        memset(vis,0,sizeof(vis));
        set<int> s;
        int l,r;
        scanf("%d %d",&l,&r);
        int pos = 0;                                
        for(int i = l;i <= r;++i){
            if(s.find(a[i]) != s.end()){
                cnt[vis[a[i]]]++;
                continue;
            } 
            pos++;
            s.insert(a[i]);
            vis[a[i]] = pos;
            cnt[vis[a[i]]]++;
            
        }
        /*for(int i = 1;i <= r - l + 1;++i)
            printf("%d ",cnt[i]);
        printf("\n");*/
        int ans1 = 0,ans2 = (r - l + 1) * (r - l);
        for(int i = 1;i <= r - l + 1;++i){
            if(cnt[i] > 1)
                ans1 += cnt[i] * cnt[i] - cnt[i];
        }
        int res = gcd(ans1,ans2);
        printf("%d/%d\n",ans1 / res,ans2 / res);
    }
    return 0;
}