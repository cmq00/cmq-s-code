#include <stdio.h>
#include <string.h>

int main()
{
    char a[1000];
    gets(a);
    char c;
    scanf("%c",&c);
    int len = strlen(a), p = 1;
    //printf("%d\n",len);
    int l = 0,r = len - 1,mid;
    while(l <= r){
        mid = (l + r) / 2;
        if(a[mid] == c){
            p = 0;
            printf("%d\n",mid+ 1);
            break;
        }
        else if(a[mid] > c)
            r = mid - 1;
        else
            l = mid + 1;
    }
    if(p == 1)
        printf("*\n");
    return 0;
}



