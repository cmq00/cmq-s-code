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

Status comp(Elemtype c1,Elemtype c2)
{
    if(c1 == c2 * c2)
        return OK;
    return 0;
}

Status equal(Elemtype a,Elemtype b)
{
    if(a == b)
        return OK;
    return 0;
}

void vist(Elemtype &c)
{
    printf("%d ",c);
}

void db(Elemtype &c)
{
    c = c * c;
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

Status GetElem(Sqlist L,int i,Elemtype &e)
{
    if(i < 1 || i > L.length)
        return ERROR;
    e = L.elem[i - 1];
    return OK;
}
 
Status LocatedElem(Sqlist L,Elemtype e, Status(*compare)(Elemtype,Elemtype))
{
    int i = 1;
    Elemtype *p = L.elem;
    while(i <= L.length && !(*compare)(*p++,e))
        ++i;
    if(i <= L.length)
        return i;
    return 0;
}

Status PriorElem(Sqlist L,Elemtype cur_e,Elemtype &pre_e)
{
    int pos = LocatedElem(L,cur_e,equal);
    if(pos == -1 || pos == 1)
        return ERROR;
    pre_e = L.elem[pos - 2];
    return OK;
}

Status NextElem(Sqlist L,Elemtype cur_e,Elemtype &next_e)
{
    int pos = LocatedElem(L,cur_e,equal);
    if(pos == -1 || pos == L.length)
        return ERROR;
    next_e = L.elem[pos - 2];
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

Status ListTraverse(Sqlist L,void(*vi)(Elemtype&))
{
   for(int i = 1;i <= L.length;++i){
       (*vi)(L.elem[i - 1]);
   }
   return OK;
}

int main()
{
    //算法2.2
    puts("");
    Sqlist La,Lb,Lc;
    InintList(La);
    InintList(Lb);
    InintList(Lc);//初始化

    int n;
    printf("La元素个数:\n");
    cin >> n;
    for(int i = 1;i <= n;++i){
        Elemtype x;
        scanf("%d",&x);
        ListInsert(La,i,x);
    }

    printf("Lb元素个数:\n");
    cin >> n;
    for(int i = 1;i <= n;++i){
        Elemtype x;
        scanf("%d",&x);
        ListInsert(Lb,i,x);
    }
    
    Elemtype i = 1,j = 1,k = 0;
    Elemtype ai,bi;
    int lena = La.length;
    int lenb = Lb.length;

    while(i <= La.length && j <= Lb.length){
        GetElem(La,i,ai);//取La中第i个元素
        GetElem(Lb,j,bi);//取Lb中第j个元素
        if(ai < bi)//如果ai小于bi，则把ai插入到Lc中
            ListInsert(Lc,++k,ai),++i;
        else
            ListInsert(Lc,++k,bi),++j;
    }

    while(i <= La.length){//将La中剩余的元素插入到Lc中
         GetElem(La,i++,ai);
         ListInsert(Lc,++k,ai);
    }
    while(j <= Lb.length){//将Lb中剩余的元素插入到Lc中
        GetElem(Lb,j++,bi);
        ListInsert(Lc,++k,bi);
    }

    printf("Lc: ");
    for(int i = 1;i <= Lc.length;++i)
        printf("%d ",Lc.elem[i - 1]);
    puts("");
}
