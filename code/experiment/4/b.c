#include <stdio.h>

int a[10000];
int fun(int i,int n)
{
    int j,k,ans1,ans2,ans3;
    //for(i = 1;i < n;++i){
        ans1 = 1,ans2 = 1;
        for(j = n;j > n - i;j--)
            ans1 *= j;
        for(k = 1;k <= i;k++)
            ans2 *= k;
        //printf("%d %d\n",ans1,ans2);
        ans3 = ans1 / ans2;
//}
    return ans3;
}


            
        

    

int main()
{
    int n,j,k;
    scanf("%d",&n);
    a[0] = 1;
    for(int i = 0;i <= n;++i){
        for(int j = 1;j < n;++j){
            a[j] = fun(j,i);
        }
        a[i] = 1;
            for(int k = 0;k <= i;++k)
                printf("%d ",a[k]);
            printf("\n");
    }
    return 0;
}
    
