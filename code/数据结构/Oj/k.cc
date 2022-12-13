#include <bits/stdc++.h>

using namespace std;

#define MAXSIZE 12500
#define TRUE 1
#define ERROR 0
#define OK 1
#define FAlSE 0

typedef int ElemType;
typedef int Status;

int num[MAXSIZE],cpot[MAXSIZE];
ElemType ans[5000][5000];

typedef struct{
    int i,j;
    ElemType e;
}Triple;

typedef struct{
    Triple data[MAXSIZE + 1];
    int mu,nu,tu;
}TSMatrix;


Status CreatTSMatrix(TSMatrix &M)
{
    int i,m,n;
    ElemType e;
    cin >> M.mu >> M.nu >> M.tu;
    M.data[0].i = 0;
    for(i = 1;i <= M.tu;++i){
        cin >> m >> n >> e;
        M.data[i].i = m;
        M.data[i].j = n;
        num[n]++;
        M.data[i].e = e;
    }  
    return OK;
}

void Initcpot(TSMatrix M)
{
    cpot[1] = 1;
    for(int col = 2;col <= M.nu;++col){
        cpot[col] = cpot[col - 1] + num[col - 1];
    }
}

Status TransposeTSMatrix(TSMatrix M,TSMatrix &T)
{
    T.mu = M.nu,T.nu = M.mu,T.tu = M.tu;
    if(T.tu){
        for(ElemType p = 1;p <= M.tu;++p){
            ElemType col = M.data[p].j;
            ElemType q = cpot[col];
            T.data[q].i = M.data[p].j;
            T.data[q].j = M.data[p].i;
            T.data[q].e = M.data[p].e;
            ++cpot[col];
        }
    }
    return OK;
}

int main()
{
    TSMatrix M,T;
    CreatTSMatrix(M);
    Initcpot(M);
    TransposeTSMatrix(M,T);
  
    for(int i = 1;i <= T.tu;++i){
        ans[T.data[i].i][T.data[i].j] = T.data[i].e;
    }
    for(int i = 1;i <= T.mu;++i){
        for(int j = 1;j <= T.nu;++j){
            if(ans[i][j]){
                if(j == T.mu)
                    cout << ans[i][j];
                else
                    cout << ans[i][j] << " ";
            }
            else{
                if(j == T.mu)
                    cout << "0";
                else
                    cout << "0 ";
            }
        }
        puts("");
    }
    return 0;
}
