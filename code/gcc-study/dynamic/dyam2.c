#include <stdio.h>

int main()
{
    int coins[] = {2, 5, 10};
    int amount = 7;
    int a[amount + 1];
    int min, i,j;
    int c = sizeof(coins) / sizeof(coins[0]);
    
    a[0] = 0;
    for(i = 1;i <= amount;i++)
        a[i] = -1;


    for(i = 1; i <= amount; i++) {
        min = 10000;
        for (j = 0; j < c; j ++) {
            if (coins[j] > i)
                continue;
            
            if (a[i - coins[j]] != -1 && a[i - coins[j]] < min)
                min = a[i - coins[j]];

            if (min != 10000) 
                a[i] = min + 1;
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


