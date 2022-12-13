#include <stdio.h>

int main()
{
    int a[1000][1000];
    int n;
    scanf("%d",&n);
    int i = 1,j = n / 2 + 1;
    int num = 1;
    a[i][j] = num;
    while(num < n * n){
        if(i - 1 <= 1){
            i = n;
            a[i][j + 1


