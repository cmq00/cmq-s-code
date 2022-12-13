#include <bits/stdc++.h>

using namespace std;

#define TRUE 1
#define ERROR 0
#define OK 1
#define FAlSE 0
#define INFEASIBLE -1

#define maxsize 100
#define ListIncrement 10
 
typedef int Status;
typedef int ElemType;

typedef struct 
{ 
    ElemType *elem;
    int length;
    int listsize;
}Sqlist;

Status comp(ElemType c1,ElemType c2)
{
    if(c1 == c2 * c2)
        return OK;
    return 0;
}

Status equal(ElemType a,ElemType b)
{
    if(a == b)
        return OK;
    return 0;
}

void visit(ElemType &c)
{
    printf("%d ",c);
}

void db(ElemType &c)
{
    c = c * c;
}

Status InintList(Sqlist &L)
{
    L.elem = (ElemType *)malloc(maxsize * sizeof(ElemType));
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

Status GetElem(Sqlist L,int i,ElemType &e)
{
    if(i < 1 || i > L.length)
        return ERROR;
    e = L.elem[i - 1];
    return OK;
}
 
Status LocatedElem(Sqlist L,ElemType e, Status(*compare)(ElemType,ElemType))
{
    int i = 1;
    ElemType *p = L.elem;
    while(i <= L.length && !(*compare)(*p++,e))
        ++i;
    if(i <= L.length)
        return i;
    return 0;
}

Status PriorElem(Sqlist L,ElemType cur_e,ElemType &pre_e)
{
    int pos = LocatedElem(L,cur_e,equal);
    if(pos == -1 || pos == 1)
        return ERROR;
    pre_e = L.elem[pos - 2];
    return OK;
}

Status NextElem(Sqlist L,ElemType cur_e,ElemType &next_e)
{
    int pos = LocatedElem(L,cur_e,equal);
    if(pos == -1 || pos == L.length)
        return ERROR;
    next_e = L.elem[pos - 2];
    return OK;
}

Status ListInsert(Sqlist &L,int i,ElemType e)
{
    if(i < 1 || i > L.length + 1)
        return ERROR;
    if(L.length >= L.listsize){
        L.elem = (ElemType *)realloc(L.elem,(L.listsize + ListIncrement) * sizeof(ElemType));
        if(!L.elem)
            exit(OVERFLOW);
         L.listsize += ListIncrement;
        } 
    ElemType *q = &(L.elem[i - 1]);
    for(ElemType *p = &(L.elem[L.length - 1]);p >= q;--p){
        *(p + 1) = *p;
    }
    *q = e;
    L.length++;
    return OK;
}

Status ListDelete(Sqlist &L,int i,ElemType &e)
{
    if(i <  1 || i > L.length)
            return ERROR; 
    ElemType *p = &(L.elem[i - 1]);
        e = *p; 
    ElemType *q = &(L.elem[L.length - 1]);
    for(p++;p <= q;++p){
        *(p - 1) = *p;
    }
    L.length--;
    return OK;
}

Status ListTraverse(Sqlist L,void(*vi)(ElemType&))
{
   for(int i = 1;i <= L.length;++i){
       (*vi)(L.elem[i - 1]);
   }
   return OK;
}

int main()
{
    Sqlist L;
    InintList(L);//初始化L
    ElemType e;
    ElemType e0;
    printf("元素个数：");
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> e;
        ListInsert(L,i,e);
    }
    for(int i = 2;i <= L.length;){
        GetElem(L,i,e);//取第i个元素
        GetElem(L,i - 1,e0);//取第i - 1个元素
        if(e == e0){
            ListDelete(L,i,e);//如果第i个元素等于第i - 1个元素，则删除第i个元素
        }
        else
            ++i;
    }
    printf("删除后：");
    ListTraverse(L,visit);//输出L
    puts("");
    return 0;
}