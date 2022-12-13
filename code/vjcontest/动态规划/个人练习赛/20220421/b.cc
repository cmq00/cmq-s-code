#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

int cnt[1004];

void solve()
{
    int n,m;
    cin >> n >> m;
    char a[1004][1004];
    for(int i = 1;i <= n;++i)
        scanf("%s",a[i]);
    //for(int i = 1;i <= n;++i)
        //printf("%s\n",a[i]);
    while(m--){
        string s;
        cin >> s;
        int len = s.size();
        int i = 0,j = 0,k = 0;
        for(i = 1;i <= n;++i){
            j = k = 0;
            while(k < len && j < strlen(a[i])){
                //cout << " ." << endl;
                if(a[i][j] == s[k] || a[i][j] == s[k] + 32 || a[i][j] == s[k] - 32)
                    j++,k++;
                else
                    j++;
            }
            if(k == len)
                cnt[i]++;
        }
    }
    for(int i = 1;i <= n;++i)
        cout << cnt[i] << endl;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}