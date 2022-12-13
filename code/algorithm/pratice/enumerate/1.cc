#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[7][8];
    int i;
    for(i = 0;i < (1 << 6);++i){
        int k = i;
        for(int j = 1;j <= 6;++j){
            a[1][j] = k % 2;
            k /= 2;
        }
    

    //for(int i = 1;i <= 6;++i){
        for(int j = 1;j <= 6;++j)
            printf("%d ",a[1][j]);
        printf("\n");
    }

    return 0;
}
