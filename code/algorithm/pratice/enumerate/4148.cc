#include <bits/stdc++.h>

using namespace std;

int main()
{
    int p,e,i,d,count = 1;
    while(~scanf("%d %d %d %d",&p,&e,&i,&d)){
        if(p == -1 && e == -1 && i == -1 && d == -1)
            break;
        int j;
        /*for(j = d + 1;j <= 21252;++j)
            if((j - p) % 23 == 0 && (j - e) % 28 == 0 && (j - i) % 33 == 0)
                break;*/
        for(j = d + 1;j < 21252;++j)
            if((j - p) % 23 == 0)   break;
        for(;j < 21252;j += 23)
            if((j - e) % 28 == 0)   break;
        for(;j < 21252;j += 23 * 28)
            if((j - i) % 33 == 0)   break;
        printf("Case %d: the next triple peak occurs in %d days.\n",count,j - d);
        count++;
    }
    return 0;
}
