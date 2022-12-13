#include <bits/stdc++.h>

using namespace std;

#define MAXSIZE 12500
#define TRUE 1
#define ERROR 0
#define OK 1
#define FAlSE 0

typedef int ElemType;
typedef int Status;

ElemType ans[5000][5000];

typedef struct{
    int i,j;
    ElemType e;
}Triple;

typedef struct{
    Triple data[MAXSIZE + 1];
    int mu,nu,tu;
}TSMatrix;

int main()
{
    TSMatrix A,B;
    int na,nb,ta,tb;
    cin >> na >> nb >> ta >> tb;
    int n,m,e;
    for(int i = 1;i <= ta;++i){
        cin >> n >> m >> e;
        A.data[i].i = n;
        A.data[i].j = m;
        A.data[i].e = e;
    }
    for(int i = 1;i <= tb;++i){
        cin >> n >> m >> e;
        B.data[i].i = n;
        B.data[i].j = m;
        B.data[i].e = e;
    }
    for(int i = 1;i <= ta;++i){
        ans[A.data[i].i][A.data[i].j] += A.data[i].e;
    }
    for(int i = 1;i <= tb;++i){
        ans[B.data[i].i][B.data[i].j] += B.data[i].e;
    }
    for(int i = 1;i <= na;++i){
        for(int j = 1;j <= nb;++j){
            if(ans[i][j]){
                if(j == nb)
                    cout << ans[i][j];
                else
                    cout << ans[i][j] << " ";
            }
            else{
                if(j == nb)
                    cout << "0";
                else
                    cout << "0 ";
            }
        }
        puts("");
    }
}