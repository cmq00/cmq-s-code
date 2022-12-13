#include <stdio.h>

int main()
{
    int i,t,j;
    int num[10];
    printf("input 10 numbers:\n");

    for(i = 0;i < 10;i++){
        scanf("%d",&num[i]);
    }
    printf("\n");
    
    for(j = 0;j < 9;j++)
       for(i = 0;i < 9 - j;i++){
            if(num[i + 1] < num[i]){
                t = num[i];
                num[i] = num[i + 1];
                num[i + 1] = t;
        }
    }
    for(i = 0;i < 10;i++)
        printf("%d ",num[i]);
    printf("\n");
    return 0;
}

