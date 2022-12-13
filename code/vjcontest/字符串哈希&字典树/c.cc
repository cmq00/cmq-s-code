#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e6 + 4;
char a[N],b[N],c[N];
const ll p = 2333333,mod = 999999998;
ll pn[N],hsa[N],hsb[N];

void init()
{
    pn[0] = 1;
    for(int i = 1;i < N;++i)
        pn[i] = pn[i - 1] * p % mod;
}

ll sbHash(ll hs[],int l,int r)
{
    return (hs[r] - hs[l - 1] * pn[r - l + 1] % mod + mod) % mod;
}

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",a + 1);
    n -= 1;
    init();
    int j = 0;
    for(;j <= strlen(a + 1);++j)
        c[j] = a[j];
    int lena = 1;
    while(n--){ 
        //printf("j:%d\n",j - 1);
        int pos = 1,flag = 0;
        scanf("%s",b + 1);
        //printf("a:%s\nb:%s\n",a,b);
        int lenb = strlen(b + 1);
        //hsa[pos - 1] = 0;
        //printf("lena:%d %c j - 1:%d\n",lena,c[lena],j - 1);
        for(int i = lena;i <= j - 1;++i)
            hsa[i] = (hsa[i - 1] * p + c[i]) % mod;
        lena = j;
        for(int i = 1;i <= lenb;++i)
            hsb[i] = (hsb[i - 1] * p + b[i]) % mod;
        
        for(int i = j - 1 - lenb;i <= j - 1;++i){
            if(i <= 0)
                continue;
            //printf("%d",i);
            if(c[i] == b[1])
                if(sbHash(hsa,i,j - 1) == sbHash(hsb,1,j - 1 - i + 1))
                    {pos = i;flag = 1;break;}
        }
        //printf("pos:%d\n",pos);
        if(flag == 0)
            for(int i = 1;i <= lenb;++i)
                c[j++] = b[i];
        else
            for(int i = j - 1 - pos + 2;i <= lenb;++i)
                c[j++] = b[i];
       /* printf("c:");
         for(int i = 1;i < j;++i)
        printf("%c",c[i]);
        printf("\n");*/
    }
    for(int i = 1;i < j;++i)
        printf("%c",c[i]);
    printf("\n");
    return 0;
}
