#include <bits/stdc++.h>

using namespace std;

int n,blocks[7][8],ans[7][8];

bool check()
{
    int i,j;
    for(i = 2;i <= 6;++i)
        for(j = 1;j <= 6;++j)
            ans[i][j] = blocks[i -1][j] ^ ans[i - 1][j] ^ ans[i - 1][j - 1] ^ ans[i - 1][j + 1] ^ ans[i - 2][j];

    for(i = 1;i <= 6;++i)
        if(ans[6][i] == 1)  return 0;
    return 1;
}

void solve()
{
    int i,j,k;
    for(i = 0;i < (1 << 6);++i){
        k = i;
        for(j = 1;j <= 6;++j){
            ans[1][j] = k % 2;
            k /= 2;
        }
        if(check()) break;
    }

    for(i = 1;i <= 5;++i){
        for(j = 1;j <= 6;++j)
            printf("%d ",ans[i][j]);
        printf("\n");
    }
}

int main()
{
    for(int i = 1;i <= 5;++i)
        for(int j = 1;j <= 6;++j)
            scanf("%d ",&blocks[i][j]);
    solve();
    return 0;
}
