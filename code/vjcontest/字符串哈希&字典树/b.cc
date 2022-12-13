#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 5000,p = 131;
const ll mod = 1e9 + 7;
int hsa[N],hsb[N];

int main()
{
    char a[N],b[N];
    while(~scanf("%s",a + 1)){
        if(a[1] == '#' && strlen(a + 1) == 1)
            break;
        memset(hsb,0,sizeof(hsb));
        memset(hsa,0,sizeof(hsa));
        scanf("%s",b + 1);
        int lena = strlen(a + 1);
        int lenb = strlen(b + 1);
        for(int i = 1;i <= lenb;++i)
            hsb[i] = (hsb[i - 1] * p + b[i]) % mod;
        int pos = 1,cnt = 0;
        while(pos <= lena){
            if(pos + lenb - 1 > lena)
                break;
            hsa[pos - 1] = 0;
            for(int i = pos;i <= lenb + pos - 1;++i)
                hsa[i] = (hsa[i - 1] * p + a[i]) % mod;
            if(hsa[lenb + pos - 1] == hsb[lenb]){
                cnt++;
                pos += lenb;
            }
            else
                pos++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
