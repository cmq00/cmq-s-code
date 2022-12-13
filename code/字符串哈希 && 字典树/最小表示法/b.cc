#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 4;
char a[N * 2  +4],b[N];
int n;

int check()
{
    int i = 0,j = 0,k = 0;
    while(i < 2 * n && j < 2 * n && k < 2 * n){
        if(a[i + k] == b[j + k])    
            k++;
        else{
            i += k + 1;
            k = 0;
        }
        if(k == n)
            return 1;
    }
    return 0;
}

int main()
{
    scanf("%d",&n);
    scanf("%s",a);
    scanf("%s",b);
    for(int i = 0;i < 2 * n;++i)
        a[i + n] = a[i];
    int la = strlen(a);
    int lb = strlen(b);
    if(check() == 1)
        puts("yes");
    else
        puts("no");
    return 0;
}