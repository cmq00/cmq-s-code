#include <stdio.h>

int main()
{
    int a[20];
    for(int i = 0;i < 10;++i)
        scanf("%d",&a[i]);
    for(int i = 0;i < 9;++i){
        for(int j = 0;j < 9 - i;++j){
            if(a[j] > a[j + 1]){
                int t;
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    printf("the sorted numbers:\n");
    for(int i = 0;i < 10;++i)
        printf("%d",a[i]);
    return 0;
}
