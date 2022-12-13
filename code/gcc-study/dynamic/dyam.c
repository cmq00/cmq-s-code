#include <stdio.h>

int main()
{
    int coins[] = {1,2,5};
    int amount = 21;
    int a[amount + 1];
    int min = coins[0],i,j;
    int c = sizeof(coins) / sizeof(coins[0]);
    
    a[0] = 0;
    for(i = 1;i <= amount;i++)
        a[i] = -1;

    for(i = 0;i < c;i++){
        if(min > coins[i])
            min = coins[i];
        }

    for(i = 0;i <= amount;i++){
        if((min + i) > amount)
            break;
        if(a[i] == -1)
            continue;
        for(j = 0;j < c;j++){
            if(i + coins[j] <= amount && i + coins[j] > 0){
                if(a[i + coins[j]] == -1 || a[i + coins[j]] > a[i] + 1)
                    a[i + coins[j]] = a[i] + 1;
            }
        }
    }

        for(i = 0;i < c;i++)
            printf("%d ",coins[i]);
        printf("\n");

        for(i = 0;i <= amount;i++)
            printf("%d ",a[i]);
        printf("\n");

        printf("%d\n",a[amount]);

        return 0;

    }


