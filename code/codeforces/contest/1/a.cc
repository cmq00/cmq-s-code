#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c,flag = 0;
        scanf("%d %d %d",&a,&b,&c);
        if(a == b + c || b == a + c || c == a + b)
            flag = 1;
        if(a % 2 == 0)
            if(b == c)
                flag = 1;
        if(b % 2 == 0)
            if(a == c)
                flag = 1;
        if(c % 2 == 0)
            if(b == a)
                flag = 1;
        if(flag == 1)
            printf("YES\n");
        else    
            printf("NO\n");
    }
    return 0;
}