#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

int cmp(const void *a,const void *b){
  return *(int *)a - *(int*)b;
}
int main()
{
    //int a[5000000];
    int *a = malloc(5000000 * sizeof(int));
    int n,j;
    while(scanf("%d",&n) != EOF){;
    for(j = 0;j < n;j++)
        scanf("%d",&a[j]);

    /*for(j = 0;j < n;j++) 
        a[j] = 0 + rand() % (10);
    for(j = 0;j < n;j++)
        printf("%d ",a[j]);
    printf("\n");*/
    qsort(a,n,sizeof(int),cmp);
   /* for(j = 0;j < n;j++)
        printf("%d ",a[j]);
    printf("\n");*/
    int k,p = 0,num = 1;

    for(j = 1,k = 0;j < n;j++)
        if(a[j] != a[k])
            a[++k] = a[j];
    k++;
    printf("%d\n",k);
    for(p = 0;p < k;p++){
    if(num == 1){
        printf("%d",a[p]);
        num++;
       }
    else
        printf(" %d",a[p]);
    }    
printf("\n");
    }
    return 0;
}