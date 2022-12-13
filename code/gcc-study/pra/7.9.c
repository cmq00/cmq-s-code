#include <stdio.h>

int main()
{
    int max(int x,int y);
    int num[10];
    int m,i,n;

    for(i = 0;i < 10;i++)
        scanf("%d",&num[i]);
    printf("\n");
    
    for(i = 0,m = num[0],n=0;i < 10;i++){
        if(max(m,num[i]) > m){
            m = max(m,num[i]);
            n = i;
        }
    }


    printf("%d,%d\n",m,n + 1);
}

int max(int x,int y)
{
    return(x > y? x:y);
}
