#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define ERROR 0
#define OK 1
#define FAlSE 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int status;
typedef int elemtype;

#define maxsize 100
#define listincrement 10

typedef struct 
{
    elemtype *elem;
    int len;
    int size;
}sqlist;

status InitList(sqlist *L)
{
    (*L).elem = (elemtype *)malloc(maxsize * sizeof(elemtype));
    (*L).size = maxsize;
    if(!(*L).elem) exit(OVERFLOW);
    (*L).len = 0;
    return OK;
}

status ValueList(sqlist *L,int num)
{
    for(int i = 0;i < num;++i){
        scanf("%d",&(*L).elem[i]);
    }
    (*L).len = num;
    return OK;
}

void DestoryList(sqlist *L)
{
    if((*L).elem)
        free((*L).elem);
}

void ClearList(sqlist *L)
{
    (*L).len = 0;
}


status GetLength(sqlist L)
{
    return L.len;
}

status IsEmpty(sqlist L)
{
    if(L.len == 0)
        return OK;
    else
        return 0;
}

status GetElem(sqlist L,int i,elemtype *e)
{
    if(i < 1 || i > L.len)
        return ERROR;
    *e = L.elem[i - 1];
    return OK;
}

status LoctedElem(sqlist L,elemtype e)    //返回第一个满足判断条件的元素
{
    int i = 0;
    elemtype *p = L.elem;
    for(int i = 0;i < L.len;++i){
        if(L.elem[i] == e)
        return i + 1;
    }
    return 0;
}

status ListInsert(sqlist *L,int i,elemtype e)   //插入
{
    if(i < 1 || i > (*L).len + 1)
        return ERROR;
    if((*L).len >= (*L).size){
        // elemtype *newlist = new elemtype[L.len];
        // if(!newlist)
        //     exit(OVERFLOW);
        // for(int j = 0;j <= L.len;++j)
        //     newlist[j] = L.elem[j];
        // L.size += listincrement;
        // delete[] L.elem;
        // L.elem = new elemtype[L.size];
        // for(int j = 0;j <= L.len;++j)
        //     L.elem[j] = newlist[j];
        (*L).elem = (elemtype*)realloc((*L).elem,((*L).size + listincrement) * sizeof(elemtype));
            exit(OVERFLOW);
        (*L).size += listincrement;
    }
    elemtype *q = &((*L).elem[i - 1]);
    for(elemtype *p = &((*L).elem[(*L).len - 1]);p >= q;--p){
        *(p + 1) = *p;
    }
    *q = e;
    ++(*L).len;
    return OK;
}

status ListDelete(sqlist *L,int i)  //删除
{
    if(i < 1 || i > (*L).len)
        return ERROR;
    elemtype *p = &((*L).elem[i - 1]);
    elemtype *q = &((*L).elem[(*L).len - 1]);
    for(p++;p <= q;++p){
        *(p - 1) = *p;
    }
    (*L).len--;
    return OK;
}

status GetPre(sqlist L,elemtype e,elemtype *pre)
{
    int pos = LoctedElem(L,e);
    if(pos == -1 || pos == 1)
        return ERROR;
    *pre = L.elem[pos - 2];
    return OK;
}

status GetNext(sqlist L,elemtype e,elemtype *next)
{
    int pos = LoctedElem(L,e);
    if(pos == -1 || pos == L.len)
        return ERROR;
    *next = L.elem[pos];   
    return OK;
}

status PrintList(sqlist L)
{
    //cout << "!" << endl;
    for(int i = 0;i < L.len;++i){
        printf("%d ",L.elem[i]);
    }
    puts(" ");
    return OK;
}

int main()
{
    sqlist L;
    InitList(&L);
    ValueList(&L,5);
    PrintList(L);
    DestoryList(&L);
    PrintList(L);
}

