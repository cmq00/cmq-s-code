#include <bits/stdc++.h>

using namespace std;

int main()
{
    char a[1000004];
    int cnt[10];
    scanf("%s",a);
    int len = strlen(a);
    cnt[5] = len;
    for(int i = 0;i < len;++i){
        if(a[i] == '5'){
            cnt[5]--;
            continue;
        }
        cnt[a[i] - '0']++;
    }
    for(int i = 1;i <= 9;++i)
        printf("%d ",cnt[i]);
    printf("\n");
    return 0;
}