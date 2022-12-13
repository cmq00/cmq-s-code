#include <stdio.h>
const int max = 1e5 + 4;
int main()
{   
    long long hash[max] = {0};
    long long num[max];
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i < n;++i){
        scanf("%lld",&num[i]);
        hash[num[i]] = 1;
    }
    int count = 0;
    for(int i = 0;i < n;++i)
        if(hash[num[i] + m] == 1)
            count++;
    printf("%d\n",count);
    return 0;
}
