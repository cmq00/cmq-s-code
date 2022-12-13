#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int main()
{
    int t;
    int a[N],sum,flag;
    scanf("%d",&t);
    while(t--){
        int vis[N] = {0};
        int n,s;
        flag = sum = 0;
        scanf("%d %d",&n,&s);
        for(int k = 1;k <= n;++k){
            scanf("%d",&a[k]);
            sum = sum + a[k];
            //cout << "flag: " << flag << endl;
            //cout << sum[k] << " ";
            if(sum - s >= 0 && vis[sum - s])
                flag = 1;
            vis[sum] = 1;
        }
        //cout << endl;
        //for(int i = 1;i <= n;++i)
            //printf("%d ",sum[i]);
        //cout << endl;
        
      
        if(flag == 1)
            printf("Yes\n");
        else    
            printf("No\n");
    }
    return 0;
}