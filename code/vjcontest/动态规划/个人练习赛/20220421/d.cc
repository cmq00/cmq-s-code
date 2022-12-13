#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

int a[104][104],b[104][104];
int n,m,k;
bool vis[104][104];

void fun1()
{
    for(int i = 1;i <= k;++i){
        for(int j = 1;j <= k;++j){
            b[i][k - j + 1] = a[j][i];
        }
    }
    for(int i = 1;i <= k;++i)
        for(int j = 1;j <= k;++j)
            a[i][j] = b[i][j];
}

void fun2()
{
    for(int i = 1;i <= k;++i){
        for(int j = 1;j <= k;++j){
            b[j][k - i + 1] = a[j][i];
        }
    }
     for(int i = 1;i <= k;++i)
        for(int j = 1;j <= k;++j)
            a[i][j] = b[i][j];
}

void fun3()
{
     for(int i = 1;i <= k;++i){
        for(int j = 1;j <= k;++j){
            b[k - i + 1][j] = a[i][j];
        }
    }
     for(int i = 1;i <= k;++i)
        for(int j = 1;j <= k;++j)
            a[i][j] = b[i][j];
}

void fun4()
{
    for(int i = 1;i <= k;++i){
        for(int j = 1;j <= k;++j){
            b[k - i + 1][j] = a[j][i];
        }
    }
   for(int i = 1;i <= k;++i)
        for(int j = 1;j <= k;++j)
            a[i][j] = b[i][j];
}


void solve()
{
    cin >> n >> m;
    k = max(n,m);
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= m;++j){
            cin >> a[i][j];
            a[i][j] -= 300;
        }
    }
    string s;
    cin >> s;
    int len = s.size();
    int cnta = 0,cntc = 0;
    for(int i = 0;i < len;++i){
        if(s[i] == 'A'){
            fun1();
            cnta++;
        }
        else if(s[i] == 'B')
           fun4();
        else if(s[i] == 'C'){
            fun2();
            cntc++;
        }
        else
            fun3();
    }
    for(int i = 1;i <= k;++i){
        for(int j = 1;j <= k;++j){
            if(a[i][j] < 0){
                if(j == 1)
                    cout << a[i][j] + 300;
                else
                    cout << " " << a[i][j] + 300;
            }
        }
        cout << endl;
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int T = 1;/*
    cin >> T;//*/
    while(T--) solve();
    return 0;
}