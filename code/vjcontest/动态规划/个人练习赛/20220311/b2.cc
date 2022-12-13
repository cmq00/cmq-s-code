#include <bits/stdc++.h>
#define ll long long
#define ms(a) memset(a,0,sizeof(a))
 
using namespace std;

const int N = 5e4 + 4;
int r[N];
int c[N];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        ms(r);
        ms(c);
        int n,m;
        scanf("%d%d",&n,&m);
//        char ch = getchar();
        char mp[n + 4][m + 4];
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= m;++j){
                //scanf("%c",&mp[i][j]);
                cin >> mp[i][j];
                if(mp[i][j] == '*')
                    r[i]++,c[j]++;
            }
        }
        int ans = 1e9;
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= m;++j){
                if(mp[i][j] == '*'){
                    ans = min(ans,m - r[i] + n - c[j]);
                }
                else{
                    ans = min(ans,m - r[i] + n - c[j] - 1);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
