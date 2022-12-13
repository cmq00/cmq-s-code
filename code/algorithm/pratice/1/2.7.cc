#include <bits/stdc++.h>

using namespace std;

int n,k,ans[14],num[14];

void dfs(int n)
{
    int i,flag = n - 1;
    /*for(i = n - 1;i > 0;--i){
        if(num[i] > num[i - 1]){
            flag = i;
            break;
        }
    }*/
    while(num[flag - 1] > num[flag] && flag != 0)
        flag--;
    if(flag == 0){
        for(i = 0;i < n;++i)
            num[i] = i + 1;
        return ;
    }

    for(i = n - 1;i >= flag;--i){
        if(num[i] > num[flag - 1]){
            int t;
            t = num[flag - 1];
            num[flag - 1] = num[i];
            num[i] = t;
            break;
        }
    }

    sort(num + flag,num + n);
}

int main()
{
    int  t,i;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        for(i = 0;i < n;++i)
            scanf("%d",&num[i]);
        for(i = 0;i < k;++i)
            dfs(n);
        for(i = 0;i < n;++i)
            printf("%d ",num[i]);
        printf("\n");
    }
    return 0;
}

        

        
