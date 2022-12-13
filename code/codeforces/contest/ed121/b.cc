#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 4;
int vis[N];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        memset(vis,0,sizeof(vis));
        string a,b,c;
        cin >> a;
        b = a;c = a;
        int flag = 0,flagg = 0,pos = 0;
        for(int i = a.size();i >= 0;--i){
            int x = a[i] - '0' + a[i - 1] - '0';
            if(x >= 10)
                {pos = i - 1;break;}
        }
        for(int i = 0;i < a.size();++i){
            if(a[i] == '0' && a[i + 1] == '0')
                continue;
            else
            {
                int x = a[i] - '0' + a[i + 1] - '0';
                if(x < 10 && !flag){
                    vis[i] = 1;
                    b[i + 1] = x + '0';
                    flag = 1;
                }
                if(x >= 10 && i == pos){
                    int xx = x / 10;
                    int xxx = x % 10;
                    c[i] = xx + '0';
                    c[i + 1] = xxx + '0';
                    flagg = 1;
                    break;
                }
            }
        }
        if(flagg == 1){
            cout << c << endl;;
        }
        else if(flag == 1){
            for(int i = 0;i < b.size();++i){
                if(!vis[i])
                    cout << b[i];
            } cout << endl;
            //cout << b << endl;
        }
    }
    return 0;
}