#include <stdio.h>

int main()
{
    int coins[6] = {1, 2,7,10,20,50};
    int count[6] = {0, 0, 0, 0, 0, 0};
    int i,amount = 14,c = sizeof(coins) / sizeof(coins[0]);

    for(i = c - 1;i >= 0;i--){
        if(amount >= coins[i]){
            count[i] = count[i] + amount / coins[i];
            amount = amount % coins[i];
        }
    }

    for(i = 0;i < c;i++)
        printf("%d ",coins[i]);
    printf("\n");

    for(i = 0;i < c;i++)
        printf("%d ",count[i]);
    printf("\n");
    printf("余额：%d\n",amount);

    return 0;
}

