#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int main()
{
    int t,flag;
    int a[N];
    long long sum;
    scanf("%d",&t);
    while(t--){
        int n,s;
        sum = 0;
        flag = 0;
        scanf("%d %d",&n,&s);
        for(int i = 0;i < n;++i)
            scanf("%d",&a[i]);
        int st,en;
        st = en = 0;
        while(1){
            while(en < n && sum < s)    sum += a[en++];
            if(sum <= s)  {break;}
            sum -= a[st++];
        }
        if(sum == s)   printf("YES\n");
        else    printf("NO\n");
    }
    return 0;
}