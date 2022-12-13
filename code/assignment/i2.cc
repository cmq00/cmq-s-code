#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int a[200][200];
    int t,n,m;
    scanf("%d",&t);
    while(t--){
        memset(a,0,sizeof(a));
        scanf("%d %d",&n,&m);
        for(int i = 1;i <= n;++i){
            int x;
            scanf("%d",&x);
            a[i][x] = 1;
        }
        /*for(int i = 1;i <= n;++i){
            for(int j = 0;j < n;++j){
                printf("a[%d][%d]:%d ",i,j,a[i][j]);
            }
        printf("\n");
    }*/
    

        while(m--){
            int x1,y1,x2,y2;
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

            int ans = 0;
            for(int y = y1;y <= y2;++y){
                for(int x = x1;x <= x2;++x){
                    if(a[x][y] == 1){
                        ans++;
                        break;
                    }
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}



