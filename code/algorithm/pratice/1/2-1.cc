#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int i,sum = 0;

    for(i = 1;i <= n;++i){
        int p = 1;
        if(i % 7 == 0)
            p = 0;
        int j = i;
        while(j){
            int x = i % 10;
            if(x == 7)
                p = 0;
            j /= 10;
        }
        if(p == 0)
            continue;
        else
            sum += i * i;
    }
    printf("%d\n",sum);
    return 0;
}
            

