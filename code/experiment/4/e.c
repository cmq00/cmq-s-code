#include <stdio.h>

int check(int x)
{
    int i;
    for(i = 2;i <= x - 1;++i)
        if(x % i == 0)
            return 0;
    return 1;
}

int main()
{
    int l,r,i,j;
    scanf("%d %d",&l,&r);
    for(i = l;i <= r;i += 2){
        for(j = 3;j <= i / 2;j++){
            if(check(j) && check(i - j)){
                printf("%d=%d+%d\n",i,j,i - j);
                break;
            }
        }
    }
    return 0;
}

        
        
        
