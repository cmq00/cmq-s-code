#include <bits/stdc++.h>
using namespace std;
const int maxm=1e5+5;
int a[maxm];
int b[maxm];
int n;
int cas=1;
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        b[i]=a[i]-a[i-1];
    }
    printf("Case %d: ",cas++);
    int g=0;
    for(int i=2;i<=n;i++){
       // g=__gcd(g,b[i]);
    }
    if(g==0){
        printf("%d\n",b[1]==1);
        return ;
    }
    if(g==1){//无解
        puts("-1");
        return ;
    }
    int ans=1e9;
    for(int i=1;i*i<=g;i++){
        if(g%i==0){
            int x=i,y=g/i;
            //
            if(x>1){
                int k=b[1]/x+(b[1]%x!=0);
                ans=min(ans,k*x-b[1]);
            }
            //
            if(y>1){
                int k=b[1]/y+(b[1]%y!=0);
                ans=min(ans,k*y-b[1]);
            }
        }
    }
    printf("%d\n",ans);
}
signed main(){
    int T;scanf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}

