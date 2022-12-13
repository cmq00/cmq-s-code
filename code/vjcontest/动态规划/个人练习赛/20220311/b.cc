#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int N = 5e4 + 4;
int r[N],c[N];

void solve()
{

}
 
int main(){
    
    int T;
    scanf("%d",&T);
    while(T--){
        memset(r,0,sizeof(r));
        memset(c,0,sizeof(c));
        int n,m;
        scanf("%d %d",&n,&m);
        char mp[n + 4][m + 4];
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= m;++j){
                cin >> mp[i][j];
                if(mp[i][j] == '*')
                    r[i]++,c[j]++;
            }
        }
        int ans = 1e9;
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= m;++j){
                //printf("ans:%d r[%d]:%d c[%d]:%d\n",ans,i,r[i],j,c[j]);
                if(mp[i][j] == '.')
                    ans = min(ans,m - r[i] + n - c[j] - 1);
                else
                    ans = min(ans,m - r[i] + n - c[j]);       
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
