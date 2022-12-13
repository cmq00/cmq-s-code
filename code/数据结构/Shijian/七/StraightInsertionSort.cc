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


void Insertsort(Sqlist &L)
{
    int j;
    for(int i = 2;i <= L.length;++i){
        if(L.elem[i] < L.elem[i - 1]){
            L.elem[0] = L.elem[i];
            L.elem[i] = L.elem[i - 1];
            for(j = i - 2;L.elem[0] < L.elem[j];--j){
                L.elem[j + 1] = L.elem[j];
            }
            L.elem[j + 1] = L.elem[0];
        }
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
    Insertsort(L);
    puts("排序后:");
    ListTraverse(L,vist);
    puts("");
}