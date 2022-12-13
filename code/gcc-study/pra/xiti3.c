#include <stdio.h>

int main()
{
    char str[5][10];
    int i,j;

    for(i = 0;i < 5;i++)
        gets(str[i]);

    for(i = 0;i < 5;i++){
        for(j = 0;j < 10;j++){
            printf("%s ",str);
        }
    }
    printf("\n");
    return 0;
}
