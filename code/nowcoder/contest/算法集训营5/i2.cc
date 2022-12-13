#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 4,N1 = 1e9 + 4;
int n,q,k,p;
int a[N],ans[N];

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin >> n >> q;
    scanf("%d %d",&n,&q);
    for(int i = 1;i <= n;++i)
        //cin >> a[i];
        scanf("%d",&a[i]);
    for(int i = 1;i <= n - 1;++i){
        //printf("a[%d] - a[%d]:%d\n",i + 1,i,a[i+1]-a[i]);
        for(int j = 1;j < a[i + 1] - a[i];++j){
            ans[j] += a[i + 1] - a[i] - j;
        }
    }
    while(q--){
        //cin >> k >> p;
        scanf("%d %d",&k,&p);
         if(ans[k] >= p)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
