#include <bits/stdc++.h>

using namespace std;

int main()
{
    int L,M;

    while(~scanf("%d %d",&L,&M)){
        int l,r,dis[100000],count = 0;
        while(M--){
            scanf("%d %d",&l,&r);
            for(int i = l;i <= r;++i)
                dis[i] = 1;
        }
        for(int i = 0;i <= L;++i)
            if(!dis[i])
                count++;
        printf("%d\n",count);
    }
    return 0;
}
