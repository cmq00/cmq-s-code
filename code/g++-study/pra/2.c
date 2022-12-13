#include<stdio.h>
int main()
{
    int a,b,c,i,j;
    while(scanf("%d %d",&i,&j)!=EOF)
    {
       // b=a;
        //c=a;
        int num = 0,p = 0;
        for(a = j;a<j+i;a++)
        {
            for(b = j;b<j+i;b++)
            {
                for(c = j;c<j+i;c++)
                {
                    if(a!=b&&b!=c&&a!=c)
                    {
                        num = 100 * a + 10 * b + c;
                        printf("%d ",num);
                        p++;
                        if(p % 10 == 0)
                            printf("\n");
                    }
                }
            }
        }
        printf("\n");
        printf("Total of %d numbers.\n",p);
    }
    return 0;
}
