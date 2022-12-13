#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll p = 131;
const ll mod = 1e9 + 7;
const int N = 1e6 + 4;
char a[N],b[N];
int pn[N],hs[N],hsa[N];

void init()
{
    pn[0] = 1;
    for(int i = 1;i < N;++i)
        pn[i] = pn[i - 1] * p % mod;
}

ll sbhash(int l,int r)
{
    return (hsa[r] - hsa[l - 1] * pn[r - l + 1] % mod + mod) % mod;
}


int main()
{
    int t;
    scanf("%d",&t);
    init();
    while(t--){
        memset(hs,0,sizeof(hs));
        memset(hsa,0,sizeof(hsa));
        scanf("%s",a + 1);
        int lena = strlen(a + 1);
        //printf("%s\n",a + 1);
        for(int i = 1;i <= lena;++i){
            hsa[i] = (hsa[i - 1] * p + a[i]) % mod;
            printf("hsa[%d]:%d\n",i,hsa[i]);
        }
        //printf("\n");

        scanf("%s",b + 1);
        int lenb = strlen(b + 1);
        // printf("%s\n",b + 1);
        for(int i = 1;i <= lenb;++i)
            hs[i] = (hs[i - 1] * p + b[i]) % mod;

        int cnt = 0;
        for(int i = 1;i <= lena;++i){
            if(i + lenb - 1 > lena){
                //printf("i:%d break\n",i);
                break;
            }
            //printf("hsa[i]:%d hsa[i + lenb - 1]:%d pn:%d\n",hsa[i],hsa[i + lenb - 1],pn[i + lenb - 1 - i + 1]);
            //int res = (hsa[i + lenb - 1] - hsa[i - 1] * pn[i + lenb - 1 - i + 1] % mod) % mod;
            //printf("res:%d\n",res);
            printf("sbhash(%d,%d):%lld %d\n",i,i + lenb - 1,sbhash(i,i + lenb - 1),hs[lenb]);
            if(sbhash(i,i + lenb - 1) == hs[lenb]){
                cnt++;
                //printf("cnt:%d\n",cnt);
            }
            //printf("\n");
        }
        printf("%d\n",cnt);
    }
    return 0;
}