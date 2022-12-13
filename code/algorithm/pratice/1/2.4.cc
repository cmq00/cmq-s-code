#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num[10],v[10];
    int i;

    for(i = 1;i <= 6;++i)
        v[i] = i * i;
    while(1){
        int sum = 0,count = 1,flag = 0;
        for(i = 1;i <= 6;++i){
            scanf("%d",&num[i]);
            if(num[i] != 0)
                flag = 1;
            sum += num[i] * v[i];
        }
        if(flag == 0)
            break;
        int ans = sum / 36;
        printf("%d\n",ans);
    }
    return 0;
}

            

