#include <stdio.h>

float Max = 0,Min = 0;

int main()
{
    float average(float array[],int n);

    float aver,score[10];
    int i;

    for (i = 0;i < 10;i++)
        scanf("%f",&score[i]);
    aver = average(score,10);
    printf("%6.2f,%6.2f,%6.2f\n",Max,Min,aver);
    return 0;
}

float average(float array[],int n)
{
    int i;
    float aver,sum = array[0];
    Max = Min = array[0];
    
    for(i = 0;i < n;i++){
            if(array[i] > Max)
                Max =  array[i];
            else if(array[i] < Min)
                Min = array[i];
            sum = sum + array[i];
        }
    aver = sum / n;
    return (aver);
}
