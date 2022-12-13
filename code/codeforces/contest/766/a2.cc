#include <bits/stdc++.h>

using namespace std;

char a[100][100];
int n,m,r,c;

int solve()
{
    int flag0 = 0,flag1 = 0,flag2 = 0;
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= m;++j){
            if(a[i][j] == 'B'){
                flag2 = 1;
                if(i == r && j == c)
                    flag0 = 1;
                if(i == r || j == c)
                    flag1 = 1;             
            }
        }
    }
    //printf("flag0:%d flag1:%d flag2:%d\n",flag0,flag1,flag2);
    if(flag0 == 1)  
        return 0;
    else{
        if(flag1 == 1)
            return 1;
        if(flag2 == 1)
            return 2;
    }
    return -1;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d %d",&n,&m,&r,&c);
        for(int i = 1;i <= n;++i)
            for(int j = 1;j <= m;++j)
                //scanf("%c",&a[i][j]);
                cin >> a[i][j];
        int ans = solve();
        printf("%d\n",ans);
    }
    return 0;
}