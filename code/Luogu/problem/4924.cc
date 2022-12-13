#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    int a[510][510];
    int b[510][510];

    scanf("%d %d",&n,&m);
    int num = 1;
    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= n;++j)
            a[i][j] = num++;
    /*for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n;++j)
            printf("%d ",a[i][j]);
        printf("\n");
    }*/
    
    while(m--){
        int x,y,r,z;
        scanf("%d %d %d %d",&x,&y,&r,&z);
        if(z == 0){
            //for(int r = 1;r <= R;++r){
            int i = 0,j = 0,k = 0,p = 0;
                //for(j = y - r,i = x - r,k = y + r;j <= y + r;j++,i++,--k){
                    /*b[i][k] = a[i][j]; 
                    b[i][k] = a[i][j];
                    b[i][k] = a[i][j];*/
                    for(i = x - r,p = y + r;i <= x + r;++i,--p){
                        for(j = y - r,k = x - r;j <= y + r;++j,++k){
                            b[k][p]= a[i][j];
                        }
                    }
                
           for(i = x - r;i <= x + r;++i)
                for(j = y - r;j <= y + r;++j)
                    a[i][j] = b[i][j];   

            /*for(int i = 1;i <= n;++i){
                for(int j = 1;j <= n;++j)
                    printf("%d ",a[i][j]);
                printf("\n");
                }*/
                //cout << endl;
            }
       // }
        else{
           //for(int r = 1;r <= R;++r){
            int i = 0,j = 0,k = 0,p = 0;
                //for(j = y - r,i = x - r,k = y + r;j <= y + r;j++,i++,--k){
                    /*b[i][k] = a[i][j]; 
                    b[i][k] = a[i][j];
                    b[i][k] = a[i][j];*/
                    for(i = x - r,p = y - r;i <= x + r;++i,++p){
                        for(j = y - r,k = x + r;j <= y + r;++j,--k){
                            b[k][p]= a[i][j];
                        }
                    }
                
           for(i = x - r;i <= x + r;++i)
                for(j = y - r;j <= y + r;++j)
                    a[i][j] = b[i][j];   

        }
    }
    //cout << endl;
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n;++j)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}