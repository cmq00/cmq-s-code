#include <bits/stdc++.h>

using namespace std;

int nex[10000];
char a[1000];
int len;

void getnext()
{
    nex[1] = 1;
    for(int i = 2,j = 0;i <= len;++i){
        while(j && a[i] != a[j + 1])
            j = nex[j];
        if(a[i] == a[j + 1])
            j++;
        nex[i] = j;
    } 
}

int main()
{
    scanf("%s",a + 1);
    len = strlen(a + 1);
    getnext();
    for(int i = 1;i <= len;++i)
        cout << nex[i] << " ";
    cout << endl;
    cout << len - nex[len] << endl;
    return 0;
}