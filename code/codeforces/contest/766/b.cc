#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        int minx = 0;
        int x = n / 2 + 1,y = m / 2;
        minx = max(abs(1 - x) + abs(1 - y),minx);
        minx = max(abs(1 - x) + abs(m - y),minx);
        minx = max(abs(n - x) + abs(m - y),minx);
        minx = max(abs(n - x) + abs(1 - y),minx);
        
        if(m % 2 == 0){
            if(n % 2 == 0)
                for(int i = 1;i <= 4;++i)
                    printf("%d ",minx);
            else
                for(int i = 1;i <= 2;++i)
                    printf("%d ",minx);
            minx++;
            int k = 2,cnt;
            if(n % 2 == 0)
                cnt = n / 2 - 1;
            else
                cnt = n / 2;
            while(cnt--){
                for(int i = 1;i <= k * 4;++i)
                    printf("%d ",minx);
                minx++;
                for(int i = 1;i <= 4;++i)
                    printf("%d ",minx);
                minx++;
                k += 2;
            }
        }
        else if(m % 2 == 1){
            int k;
            if(n % 2 == 0)
                k = 2;
            else
                k = 3;
            for(int i = 1;i <= k;++i)
                printf("%d ",minx);
            minx++;
            int cnt = n / 2 - 1;
            k = k * 2 + 2;
            while(cnt--){
                for(int i = 1;i <= k;++i)
                    printf("%d ",minx);
                minx++;
                k += 2;
            }
        }
        printf("\n");
        /*if(n >= 4){
            for(int i = 1;i <= 4;++i)
                printf("%d ",minx);
            printf("\n");
        }*/
    }
    return 0;
}