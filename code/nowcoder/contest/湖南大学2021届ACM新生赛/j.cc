#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        ll x1,y1,x2,y2,a,b,c;
        scanf("%lld %lld %lld %lld %lld %lld %lld",&x1,&y1,&x2,&y2,&a,&b,&c);
        int pos1 = 0,pos2 = 0;
        if(a * x1 + b * y1 + c > 0)
            pos1 = 1;
        if(a * x2 + b * y2 + c > 0)
            pos2 = 1;
        if(pos1 == pos2)
            printf("Yes\n");
        else    
            printf("No\n");
    }
    return 0;
}