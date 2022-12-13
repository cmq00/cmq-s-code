#include <stdio.h>

int main()
{
    int i;
    float average(float array[10]);
    float score[10];
    float aver;

    for(i = 0;i < 10;i++)
        scanf("%f",&score[i]);
    printf("\n");

    aver = average(score);
    printf("%f\n",aver);
    return 0;
}


float average(float array[10])
{
    float sum = array[0],aver;
    int i;

    for(i = 0;i < 10;i++)
        sum = sum + array[i];
    aver = sum / 10;
    return (aver);
}
