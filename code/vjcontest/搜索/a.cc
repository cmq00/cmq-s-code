#include <bits/stdc++.h>//hahahahahaha

using namespace std;

int n,num[14],vis[24];

bool check(int n)
{
    int i;
    for(i = 2;i <= sqrt(n);++i){
        if(n % i == 0)
            return 0;
    }
    return 1;
}

void dfs(int n1)
{
    int i;
    if(n1 == n + 1){
        if(!check(num[1] + num[n]))
            return ;

        for(i = 1;i <= n;++i){
            if(i == 1)
                printf("%d",num[i]);
            else
                printf(" %d",num[i]);
        }
        printf("\n");
        return ;
    }

    for(i = 1;i <= n;++i){
        if(n1 == 1 && i >= 2)
            return ;
        if(!vis[i]){
            if(n1 >= 2 && !check(i + num[n1 - 1]))
                continue;
            vis[i] = 1;
            num[n1] = i;
            dfs(n1 + 1);
            vis[i] = 0;
        }
    }
}

int main()
{
    int count = 0;
    while(~scanf("%d",&n)){
        printf("Case %d:\n",++count);
        memset(vis,0,sizeof(vis));
        dfs(1);
        printf("\n");
    }
    return 0;
}