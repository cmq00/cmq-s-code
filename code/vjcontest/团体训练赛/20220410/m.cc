#include <bits/stdc++.h>
#define ll long long
using namespace std;

char C[600][600],A[600][600],B[600][600];
int rmin=600,rmax= -1,cmin= 600,cmax=-1;
int n,m;

void solve()
{
    cin >> n >> m;
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= m;++j){
            cin >> C[i][j];
            if(C[i][j] == '1'){
                rmin = min(rmin,i);
                rmax = max(rmax,i);
                cmin = min(cmin,j);
                cmax = max(cmax,j);
            }
            B[i][j] = C[i][j];
            A[i][j] = C[i][j];
        }
    }
    /*for(int i = 1;i <= n;++i){
        for(int j = 1;j <= m;++j)
            cout << C[i][j];
        cout << endl;
    }*/
    //printf("rmin:%d rmax:%d cmax:%d cmin:%d\n",rmin,rmax,cmax,cmin);
    for(int i = rmin;i <= rmax;++i){
        for(int j = cmin;j <= cmax;++j){
            A[i][j] = '1';
        }
    }

    for(int i = 1;i < rmin;++i){
        for(int j = 1;j <= m;++j){
            B[i][j] = '1';
        }
    }
    for(int i = rmin;i <= rmax;++i){
        for(int j = 1;j < cmin;++j)
            B[i][j] = '1';
        for(int j = cmax + 1;j <= m;++j)
            B[i][j] = '1';
    }
    for(int i = rmax + 1;i <= n;++i)
        for(int j = 1;j <= m;++j)
            B[i][j] = '1';

    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= m;++j){
            cout << A[i][j];
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= m;++j){
            cout <<  B[i][j];
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