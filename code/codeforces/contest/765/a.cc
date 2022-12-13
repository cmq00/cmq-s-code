#include <bits/stdc++.h>

using namespace std;

int bin[104][32];

void Bin(int x,int r)
{
    int c = 30;
    while(x > 0){
        int xx = x % 2;
        bin[r][c--] = xx;
        x /= 2;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        memset(bin,0,sizeof(bin));
        int n,t;
        scanf("%d %d",&n,&t);
        for(int i = 1;i <= n;++i){
            int x;
            scanf("%d",&x);
            Bin(x,i);
        }
        /*for(int i = 1;i <= n;++i){
            for(int j = 1;j <= 30;++j)
                printf("%d",bin[i][j]);
            printf("\n");
        }*/
        int c = 1;
        for(int j = 30;j >= 1;--j){
            int cont1 = 0,cont2 = 0;
            for(int i = 1;i <= n;++i){
                if(bin[i][j] == 0)
                    cont1++;
                else
                    cont2++;
            }
            if(cont1 > cont2)
                bin[n + 1][c++] = 0;
            else
                bin[n + 1][c++] = 1;
        }
        /*for(int j = 1;j <= 30;++j)
            printf("%d",bin[n + 1][j]);
        printf("\n");*/
        int ans = 0;
        //printf("pow(2,t):%f\n",pow(2,t));
        for(int j = 1,cont = 0;j <= t;++j,++cont){
            if(bin[n + 1][j] == 1 && ans + pow(2,cont) <= pow(2,t) - 1)
                ans += pow(2,cont);
        }
        printf("%d\n",ans);
    }
    return 0;
}