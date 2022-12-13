#include <bits/stdc++.h>

using namespace std;

#define TRUE 1
#define ERROR 0
#define OK 1
#define FAlSE 0
#define INFEASIBLE -1

#define maxsize 10
#define ListIncrement 2 
 
typedef int Status;
typedef int Elemtype;

typedef struct 
{ 
    Elemtype *elem;
    int length;
    int listsize;
}Sqlist;

int dlta[1000];

void vist(Elemtype &c)
{
    printf("%d ",c);
}

Status InintList(Sqlist &L)
{
    L.elem = (Elemtype *)malloc(maxsize * sizeof(Elemtype));
    L.listsize = maxsize;
    if(!L.elem)
        exit(OVERFLOW);
    L.length = 0;
    return OK;
}

Status DestoryList(Sqlist &L)
{
    L.length = 0;
    L.elem = 0;
    delete[] L.elem;
    L.elem = NULL; 
    return OK;
}

Status ClearList(Sqlist &L)
{
    L.length = 0;
    return OK;
}

Status ListEmpty(Sqlist L)
{
    if(L.length == 0)
        return OK;
    return -1;
} 

Status Listlengthgth(Sqlist L)
{
    return L.length;
    return OK;
}

Status ListInsert(Sqlist &L,int i,Elemtype e)
{
    if(i < 1 || i > L.length + 1)
        return ERROR;
    if(L.length >= L.listsize){
        L.elem = (Elemtype *)realloc(L.elem,(L.listsize + ListIncrement) * sizeof(Elemtype));
        if(!L.elem)
            exit(OVERFLOW);
         L.listsize += ListIncrement;
        } 
    Elemtype *q = &(L.elem[i - 1]);
    for(Elemtype *p = &(L.elem[L.length - 1]);p >= q;--p){
        *(p + 1) = *p;
    }
    *q = e;
    L.length++;
    return OK;
}

Status ListDelete(Sqlist &L,int i,Elemtype &e)
{
    if(i <  1 || i > L.length)
            return ERROR; 
    Elemtype *p = &(L.elem[i - 1]);
        e = *p; 
    Elemtype *q = &(L.elem[L.length - 1]);
    for(p++;p <= q;++p){
        *(p - 1) = *p;
    }
    L.length--;
    return OK;
}

void ShellInsert(Sqlist &L,int dk)
{
    int j;
    for(int i = dk + 1;i <= L.length;++i){
        if(L.elem[i] < L.elem[i - dk]){
            L.elem[0] = L.elem[i];
            for(j = i - dk;j > 0 && L.elem[0] < L.elem[j];j -= dk){
                L.elem[j + dk] = L.elem[j];
            }
            L.elem[j + dk] = L.elem[0];
        }
    }
}

void ShellSort(Sqlist &L,int dlta[],int t)
{
    for(int k = 1;k <= t;++k)
        ShellInsert(L,dlta[k]);
}

int t;

void Inintdlta()
{
    t = 2;
    while(1){
        dlta[t] = dlta[t - 1] / 3 + 1;
        if(dlta[t] == 1)
            break;
        t++;
    }
}

Status ListTraverse(Sqlist L,void(*vi)(Elemtype&))
{
   for(int i = 1;i <= L.length;++i){
       (*vi)(L.elem[i]);
   }
   return OK;
}

int main()
{
    Sqlist L;
    InintList(L);
    puts("输入数据个数:");
    int n,e;
    cin >> n;
    L.length = n;
    puts("输入数据:");
    for(int i = 1;i <= n;++i){
        cin >> e;
        L.elem[i] = e;
    }
    dlta[1] = n;
    Inintdlta();
    ShellSort(L,dlta,n);
    puts("排序后:");
    ListTraverse(L,vist);
    puts("");
}