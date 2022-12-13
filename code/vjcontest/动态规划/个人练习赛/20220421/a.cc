#include <bits/stdc++.h>
#define ll long long
#define ms(i) memset(i, 0, sizeof(i))
 
using namespace std;

int a[100][100],b[100][100];
int n,m,k;


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
    k = 3;
     for(int i = 1;i <= k;++i){
        for(int j = 1;j <= k;++j){
            cin >> a[i][j];
        }
    }
   
      for(int i = 1;i <= k;++i){
        for(int j = 1;j <= k;++j){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    fun4();
    for(int i = 1;i <= k;++i){
        for(int j = 1;j <= k;++j){
            cout << a[i][j] << " ";
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