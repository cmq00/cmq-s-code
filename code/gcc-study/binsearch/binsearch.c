#include <stdio.h>
#include <stdlib.h>


int cmp(const void *num1, const void *num2) {

    if (*(int *)num1 < *(int *)num2) 
        return -1;
    if (*(int *)num1 > *(int *)num2) 
        return 1;

    return 0;

}

int main()
{
    int num[10];
    int i;
    int c;
    c =  sizeof(num)/sizeof(num[0]);
    for(i = 0;i < c;i++){
        num[i] = random() % 100;
        printf("%d ",num[i]);
    }
    printf("\n");

    qsort(num,c,sizeof(num[0]),cmp);
    for(i = 0;i < c;i++){
        printf("%d ",num[i]);
    }
    printf("\n");
    int low = 0,high = c - 1,mid;
    int find = 78;
    while(low <= high){
        mid =(low + high)/2;
        if(num[mid] < find)
            low = mid + 1;
        if(num[mid] > find)
            high = mid - 1;
        if(num[mid] == find)
            break;
        }
    if(low > high)
        printf("-1\n");
    if(low <= high)
        printf("%d\n",mid);
    return 0;
}
