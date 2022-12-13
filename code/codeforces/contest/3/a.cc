#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        int flag = 1;
        if(n % 2 == 0 && m > n / 2)
            flag = 0;
        if(n % 2 != 0 && m > n / 2 + 1)
            flag = 0;
        if(flag == 0)
            printf("-1\n");
        else{
            char a[45][45];
            for(int i = 1;i <= n;++i)
                for(int j = 1;j <= n;++j)
                    a[i][j] = '.';
            int i = 1,j = 1;
            while(m--){
                a[i][j] = 'R';
                i += 2;
                j += 2;
            }
            for(int i = 1;i <= n;++i){
                for(int j = 1;j <= n;++j)
                    printf("%c",a[i][j]);
                printf("\n");
            }
        }
    }
    return 0;
}