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

void Merge(Sqlist &L,Sqlist T,int l,int mid,int r)
{
    int l_pos = l;
    int r_pos = mid + 1;
    int pos = l;
    while(l_pos <= mid && r_pos <= r){
        if(L.elem[l_pos] < L.elem[r_pos])
            T.elem[pos++] = L.elem[l_pos++];
        else
            T.elem[pos++] = L.elem[r_pos++];
    }
    while(l_pos <= mid)
        T.elem[pos++] = L.elem[l_pos++];
    while(r_pos <= r)
        T.elem[pos++] = L.elem[r_pos++];
    while(l <= r){
        L.elem[l] = T.elem[l];
        l++;
    }
    puts("");
}

void Msort(Sqlist &L,Sqlist T,int l,int r)
{
    if(l < r){
        int mid = (l + r) / 2;
        Msort(L,T,l,mid);
        Msort(L,T,mid + 1,r);
        Merge(L,T,l,mid,r);
    }
}

void MergeSort(Sqlist &L)
{
    Sqlist T;
    InintList(T);
    Msort(L,T,1,L.length);
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
    Sqlist L,T;
    InintList(L);
    InintList(T);
    puts("输入数据个数:");
    int n,e;
    cin >> n;
    L.length = n;
    puts("输入数据:");
    for(int i = 1;i <= n;++i){
        cin >> e;
        L.elem[i] = e;
    }
    MergeSort(L);
    puts("排序后:");
    ListTraverse(L,vist);
    puts("");
}