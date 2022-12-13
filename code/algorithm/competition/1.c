#include <stdio.h>
int main()
{
    int a,b = 2;
    a = b++;
    printf("%d %d",a,b);
    int count = 0;
   // printf("%d %d %d",count++,count++,++count);
   count = count++;
   printf("%d",count);
    return 0;
}
