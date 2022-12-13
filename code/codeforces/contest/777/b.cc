#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 200;
char a[N][N];

bool check(int i,int j)
{
    if(a[i][j - 1] == '1' && a[i - 1][j] == '1' && a[i - 1][j - 1] == '1')
        return 1;
    if(a[i][j + 1] == '1' && a[i - 1][j] == '1' && a[i - 1][j + 1] == '1')
        return 1;
    if(a[i][j - 1] == '1' && a[i + 1][j] == '1' && a[i + 1][j - 1] == '1')
        return 1;
    if(a[i][j + 1] == '1' && a[i + 1][j] == '1' && a[i + 1][j + 1] == '1')
        return 1;
    return 0; 
}

void solve()
{
    memset(a,0,sizeof(a));
    int n,m;
    cin >> n >> m;
    //cout << "!" << endl;
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= m;++j){
            cin >> a[i][j];
        }
    }
    //cout << "!" << endl;
    int flag = 0;
    for(int i = 1; i <= n;++i){
        if(flag == 1)
            break;
        for(int j = 1;j <= m;++j){
            if(a[i][j] == '0'){
                if(check(i,j)){
                    flag = 1;
                    continue;
                }
            }
        }
    }
    if(flag == 1)
        puts("NO");
    else
        puts("YES");
}
 
int main(){
    //ios_base::sync_with_stdio(0);
    int T = 1;//*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}