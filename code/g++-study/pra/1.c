#include <stdio.h>

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    int i,j,k,num = 0;
    for(i = m;i < m + n;i++){
        for(j = m;j < m + n;j++){
            for(k = n;k < m + n;k++){
                if(i != j && j != k && i != k){
                    printf("%d%d%d ",i,j,k);
                    num++;
                }
            }
        }
    }

    printf("\n");
    printf("%d",num);
    return 0;
}
