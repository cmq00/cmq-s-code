#include <bits/stdc++.h>

using namespace std;

int main()
{
    char a[100][100];
    int t;
    scanf("%d",&t);
    while(t--){
        int ans = 2;
        int flag = 0,flag1 = 0;;
        int n,m,r,c;
        scanf("%d %d %d %d",&n,&m,&r,&c);
        for(int i = 1;i <= n;++i)
            for(int j = 1;j <= m;++j)
               cin >> a[i][j];

        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= m;++j){
                if(a[i][j] == 'B'){
                    flag = 1;
                    //printf("i:%d j:%d r:%d c:%d\n",i,j,r,c);
                    if(i == r && j == c)
                        {ans = 0;flag1 = 1;break;}
                    if(i == r || j == c)
                        {ans = 1;}
                }
                if(flag1 == 1)
                    break;
            }
        }
        if(flag == 0)
            ans = -1;
        printf("%d\n",ans);
    }
    return 0;
}