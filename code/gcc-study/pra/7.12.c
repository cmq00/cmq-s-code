#include <stdio.h>

int main()
{
    void sort(int array[],int n);
    int a[10],i;
    
    for(i = 0;i < 10;i++)
        scanf("%d",&a[i]);
    printf("\n");

    sort(a,10);
    
    for(i = 0;i < 10;i++)
        printf("%d ",a[i]);
    printf("\n");

    return 0;
}

void sort(int array[],int n)
{
    int i,j,t;

    for(i = 0;i < n-1;i++){
        for(j = i+1;j < n;j++){
            if(array[j] < array[i]){
                t = array[i];
                array[i] = array[j];
                array[j] = t;
            }
        }
    }
}
