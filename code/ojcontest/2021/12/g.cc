#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        if(k % (n + 1) == 0)
            printf("yaoyao\n");
        else
            printf("tangtang\n");
    } 
    return 0;
}