#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 4;
int a[N * 2 + 10];
int n;

int getmin()
{
    int i = 1,j = 2,k = 0;
    while(i <= n && j <= n && k <= 2){
        int t = a[i + k] - a[j + k];
        if(!t)  k++;
        else{
            if(t > 0)
                i += k + 1;
            else
                j += k + 1;
            if(i == j)
                j += 1;
            k = 0;
        }
    }
    return min(i,j);
}

int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;++i)
        scanf("%d",&a[i]);
    for(int i = 1;i < 2 * n;++i)
        a[i + n] = a[i];
    int pos = getmin();
    for(int i = pos;i < pos + n;++i){
        if(i == pos)    
            printf("%d",a[i]);
        else    
            printf(" %d",a[i]);
    }    
    //printf("\n");
    return 0;
}