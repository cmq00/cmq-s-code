#include <bits/stdc++.h>

using namespace std;

const int N = 550;
int n,m;
int a[N],b[N],dp[N][N],path[N][N];

bool print(int x)
{
    if(!x) 
        return false;
    if(print(path[n][x]))
        printf(" %d",b[x]);
    else    
        printf("%d",b[x]);
    return true;

}

int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;++i)
        scanf("%d",&a[i]);

    scanf("%d",&m);
    for(int i = 1;i <= m;++i)
        scanf("%d",&b[i]);

    int ans = 1;
    /*o(n^3)
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= m;++j){
            if(a[i] == b[j]){
                dp[i][j] = max(dp[i][j],1);
                for(int k = 1;k < j;++k)
                    if(b[k] < b[j])
                        dp[i][j] = max(dp[i][j],dp[i][k] + 1);
            }
            else    
                dp[i][j] = max(dp[i][j],dp[i - 1][j]);
            ans = max(dp[i][j],ans);
        }
    }*/

    /*o(n^2)

    for(int i = 1;i <= n;++i){
        int maxx = 1,pos = 0;
        for(int j = 1;j <= m;++j){
            dp[i][j] = max(dp[i][j],dp[i - 1][j]);
            path[i][j] = path[i - 1][j];
            if(a[i] == b[j])
                dp[i][j] = max(dp[i][j],maxx),path[i][j] = pos;
            if(b[j] < a[i])
                maxx = max(maxx,dp[i][j] + 1),pos = j;
            //ans = max(dp[i][j],ans);
            //cout << dp[i][j] << " " << maxx <<  endl; 
            cout << i << " " << j  << " " << path[i][j] << endl;
        }
    }*/
    //o(n^2)
    for(int i = 1;i <= n;++i){
        int val = 0,pos = 0;
        for(int j = 1;j <= m;++j){
            path[i][j] = path[i - 1][j]; 
            
            if(a[i] == b[j])
                {dp[i][j] = val + 1;path[i][j] = pos;}        
            else
               dp[i][j] = dp[i - 1][j];
               
            if(b[j] < a[i] && dp[i - 1][j] > val)
                {val = dp[i - 1][j];pos = j;}

            //printf("dp[%d][%d]: %d\n",i,j,dp[i][j]);
            //printf("path[%d][%d]: %d\n",i,j,path[i][j]);
            //cout << endl;
        }
    }

    int  maxx = 0,h;
    for(int i = 1;i <= m;++i){
        if(maxx < dp[n][i]){
            maxx = dp[n][i];
            h = i;
        }
    }
     printf("%d\n",maxx);
    if(dp[n][h])
        print(h);
    printf("\n");

   
    return 0;
}