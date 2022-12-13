#include <stdio.h>
#include <string.h>

int main()
{
    char a[1000];
    scanf("%s",a);
    int len = strlen(a);
    int i,j;
    for(i = 0,j = len - 1;i != j;i++,j--)
        if(a[i] != a[j])
            break;
    if(i == j)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
