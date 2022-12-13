#include <bits/stdc++.h>

using namespace std;

bool check(int a,int b,int c)
{
    if(a == b && a % c == 0)
        return 1;
    if((2 * b - a) > 0 && (2 * b - a) % c == 0)
        return 1;
    if(a == c && a % b == 0)
        return 1;
    int aa = 2 * b - c;
    if(aa > 0 && aa % a == 0)
      return 1;
    if(b == c && c % a == 0)
        return 1;
    int bb = (a + c) / 2;
    if(bb > 0 && bb % b == 0 && (a + c) % 2 == 0)
        return 1;
    return 0;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if(check(a,b,c))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}