#include <stdio.h>

int main()
{
    int a[] = {31,29,31,30,31,30,31,31,30,31,30,31};

    int year,mon,day;
    scanf("%d %d %d",&year,&mon,&day);

    int leap;
    if(year%4 == 0)
    {
        if(year % 100 == 0)
        {
            if(year % 400 == 0)
                leap = 1;
            else
                leap = 0;
        }
        else
            leap = 1;
    }
    else
        leap = 0;
    int sum = 0,i;
    //if(leap == 1)
    for(i = 0;i < mon - 1;++i)
        sum += a[i];
    if(leap == 1 && mon)
        printf("%d\n",sum + day);
    else{
        if(mon > 2)
            printf("%d\n",sum + day - 1);
        else
            printf("%d\n",sum + day);
        }


    /*else if(leap == 0)
        for(i = 0;

     else if(mon == 8)
        printf("31 days");
    else if(mon % 2!=0)
        printf("31 days");
    else if (mon % 2 == 0)
        printf("30 days");*/
        return 0;
    }
