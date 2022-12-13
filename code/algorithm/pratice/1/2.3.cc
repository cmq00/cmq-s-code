#include <bits/stdc++.h>

using namespace std;

int main()
{
    int L,M;
    while(~scanf("%d %d",&L,&M)){

    int dis[1000000] = {0},sum = 0;

    while(M--){
        int i,l,r;
        scanf("%d %d",&l,&r);

        if(!dis[l] && !dis[r]){
            for(i = l;i <= r;++i)
                dis[i] = 1;
            sum += r + 1 - l;
     //       printf("%d\n",sum);
        }
        
        else if(!dis[l] && dis[r]){
            for(i = l;dis[i] != 1;++i){
                dis[i] = 1;
                sum++;
            }
       // printf("%d\n",sum);
        }
        
        else if(dis[l] && !dis[r]){
            for(i = r;dis[i] != 1;i--){
                dis[i] = 1;
                sum++;
            }
        //printf("%d\n",sum);
        }
    }
    printf("%d\n",L + 1 - sum);
}
    return 0;
}
        
