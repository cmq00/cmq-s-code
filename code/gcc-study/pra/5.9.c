#include <stdio.h>
#include <math.h>

int main()
{
    int i,n;
    scanf("%d",&n);
    printf("%f\n",sqrt(n));
    for(i = 2;i <= n -1;i++){
        if(n / i == 0) break;
        }
        if(i < n) printf("n is not");
        else printf("n is");
    return 0;
}
