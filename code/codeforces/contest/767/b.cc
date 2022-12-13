#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int l,r,k;
        scanf("%d %d %d",&l,&r,&k);
        int odd = 0,even = 0;
        if(l % 2 == 0){
            if(r % 2 == 0)
                even = (r - l + 1) / 2;
            else
                 even = (r - l + 1) / 2;
        }
        else{
            if(r % 2 == 0)
                even = (r - l + 1) / 2;
            else
                 even = (r - l + 1) / 2 + 1;
        }
       /* for(int i = l;i <= r;++i){
            if(i % 2 == 0) 
                odd++;
            else    
                even++;
        }*/
        int flag = 0;
        if(l == r && l != 1)
            {printf("YES\n");continue;}
        if(l == r && l == 1)
            {printf("NO\n");continue;}
        if(even > k)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}