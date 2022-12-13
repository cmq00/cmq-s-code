#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 4;

char s[N],t[N];
int nex[N],f[N],ls,lt;

void getnext()
{
    nex[1] = 0;
    for(int i = 2,j = 0;i <= lt;++i){
        while(j && t[i] != t[j + 1])
            j = nex[j];
        if(t[i] == t[j + 1])
            j++;
        nex[i] = j;
    }
}

void kmp()
{
    int cnt = 0;
    for(int i = 1,j = 0;i <= ls;++i){
        while(j && (j == ls || s[i] != t[j + 1]))
            j = nex[j];
        if(s[i] == t[j + 1])
            j++;
        if(j == lt)
            cout << i - j + 1 << endl; 
    }
}

int main()
{
    scanf("%s",s + 1);
    scanf("%s",t + 1);
    ls = strlen(s + 1);
    lt = strlen(t + 1);
    getnext();
    kmp();
    for(int i = 1;i <= lt;++i)
        cout << nex[i] << " ";
    cout << endl;
}