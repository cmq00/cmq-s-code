#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll p = 131;
const ll mod = 1e9 + 7;
const int N = 1e6 + 4;
ll pn[N],hs[N];
char s[N];

void init()
{
    pn[0] = 1;
    for(int i = 1;i < N;++i)
        pn[i] = pn[i - 1] * p % mod;
}

ll sbHash(int l,int r)
{
    return (hs[r] - hs[l - 1] * pn[r - l + 1] % mod + mod) % mod;
}

int main()
{
    scanf("%s",s + 1);
    int len = strlen(s + 1);
    for(int i = 1;i <= len;++i)
        hs[i] = (hs[i - 1] * p + s[i]) % mod;
    init();
    int t;
    scanf("%d",&t);
    while(t--){
        int l1,l2,r1,r2;
        scanf("%d %d %d %d",&l1,&r1,&l2,&r2);
        if(sbHash(l1,r1) == sbHash(l2,r2))
            printf("Yes\n");
        else    
            printf("No\n");
    }
    return 0;
}



