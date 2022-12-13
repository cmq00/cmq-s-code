#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[2000];
    int len[2000];
    int n;
    scanf("%d",&n);

    for(int i = 1;i <= n;++i){
        scanf("%d",&a[i]);
        len[i] = 1;
    }

    for(int i = 2;i <= n;++i)
        for(int j = 1;j < i;++j)
            if(a[i] > a[j])
                len[i] = max(len[i],len[j] + 1);

    
    int ans = -1;
    for(int i = 1;i <= n;++i)
        ans = max(len[i],ans);
    printf("%d\n",ans);
    return 0;
}