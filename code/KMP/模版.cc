#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 4;
char a[N],b[N],n,m;
int nex[N],f[N];

void getnext()
{
    nex[1] = 0; 
    for(int i = 2,j = 0;i <= n;++i){ 
        while(j && a[i] != a[j + 1]) j = nex[j]; 
        if(a[i] == a[j + 1])
            j++;
        nex[i] = j;
    }
    for(int i = 1;i <= n;++i)
        cout << nex[i] << " " ;
    cout << endl;
}

void kmp()
{
    int cnt = 0;
    for(int i = 1,j = 0;i <= m;++i){
        while(j && (j == n || b[i] != a[j + 1]))
            j = nex[j];
        if(b[i] == a[j + 1])
            j++;
        f[i] = j;
        if(j == n)
            cnt++;
    }
    cout << cnt << endl;
}

int main()
{
    scanf("%s",b + 1);
    scanf("%s",a + 1);
    m = strlen(b + 1);
    n = strlen(a + 1);
    getnext();
    kmp();
    return 0;
}
