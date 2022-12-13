#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T=0;
    scanf("%d", &T);
    while(T--){
    int n,m,x0,y0,x1,y1,a,b;
    int d=0;
    int arr[100][100];
    int b[100];
    int a[100];
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i=1;i<=n;i++){
       scanf("%d", &a);
       arr[i][a]=1;
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<5;j++){
    //         printf("%2d", arr[i][j]);
            
    //     }
    //     printf("\n");
    // }
    b=0;
    for(int t=0;t<m;t++){
    scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
    for(int i=y0;i<=y1;i++){
        for(int j=x0;j<=x1;j++){
            if(arr[i][j]==1){
               b++;
               break;
            }

        }
    }
     b[t]=b;
    //printf("%d\n", b-1);
    b=0;
    }
    for(int i=0;i<m;i++){
        cout << b[i] << endl;
    }
    }
    // for(int i=x0;i<=x1;i++){
    //     for(int j=y0;j<=y1;j++){
    //         if(arr[i][j]==1){
    //            b++;
    //            break;
    //         }

    //     }
    // }
    //printf("%d\n", b);
    return 0;
}