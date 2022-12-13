#include <stdio.h>

int main()
{
    void sort(int x[],int n);

    int a[10],i,*p;
    p = a;

    for(p = a;p < (a + 10);p++)
        scanf("%d",p);
    printf("\n");
    p = a;

    sort(a,10);

    for(p = a;p < (a + 10);p++)
        printf("%d ",*p);
    printf("\n");

    return 0;
}

void sort(int x[],int n)
{
    int i,j,k,t;

    for(i = 0;i < n - 1;i++){
        k = i;
        for(j = i + 1;j < n;j++)
            if(x[j] > x[k])
                k = j;
            if(k != i){
                t = x[i];
                x[i] = x[k];
                x[k] = t;
            }
        }
}
    
