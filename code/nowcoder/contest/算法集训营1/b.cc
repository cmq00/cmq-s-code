#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,q;
    scanf("%d %d",&n,&q);
    char a[200004];
    scanf("%s",a + 1);
 
    while(q--){
        int l,r,ans = 0,flag = 0;
        scanf("%d %d %d",&l,&r,&ans);
        for(int i = l;i <= r;++i){
            if(ans % 3 == 0)
                flag = 1;
            if(ans % 3 != 0)
                flag = 0;
            if(a[i] == 'W')
                ans++;
            if(a[i] == 'L'){
                if(flag == 1)
                    flag = 0;
                else{
                    if(ans != 0)
                        ans--;
                }
            }
            //printf("%d ",ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}