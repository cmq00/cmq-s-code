#include <stdio.h>
#include <string.h>

int main()
{
    int a[1000];
    int x,n,i = 0,len = 0;
    scanf("%d",&n);
    while(n > 0){
        x = n % 16;
        a[i] = x;
        n /= 16;
        i++;
        len++;
    }
    for(i = len - 1;i >= 0;i--){
        if(a[i] < 10)
            printf("%d",a[i]);
        else
            printf("%c",a[i] + 55);
    }
    return 0;
}

