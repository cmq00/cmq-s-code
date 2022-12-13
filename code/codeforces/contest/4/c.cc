#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        map<int,int> mp;
        int n;
        scanf("%d",&n);
        for(int i = 1;i <= n;++i){
            int x;
            scanf("%d",&x);
            while(x > 0){
                if(x <= n && mp.count(x) == 0)
                    {mp[x] = x;break;} 
                x /= 2;
            }
        }
        int flag = 1;
        for(int i = 1;i <= n;++i)
            if(mp[i] != i)
                {flag = 0;break;}
        if(flag == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}