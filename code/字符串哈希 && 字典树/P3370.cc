#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll p = 131;
const ll mod = 1e9 + 7,N = 1e9;
ll hs[1504],a[10004];
char s[1504];

int main()
{
    int t;
    int ans;
    scanf("%d",&t);
    ans = t;int j = 0;
   for(int i = 0;i < t;++i){
        scanf("%s",s + 1);
        int len = strlen(s + 1);
        //cout << "len: " << len << endl;
        for(int k = 1;k <= len;++k)
            hs[k] = (hs[k - 1] * p + s[k]) % mod;
        a[j++] = hs[len];
    }
    sort(a,a + t);
    for(int i = 0;i < t;++i)
        if(a[i] == a[i - 1])
            ans--;
   printf("%d\n",ans);
    return 0;
}
