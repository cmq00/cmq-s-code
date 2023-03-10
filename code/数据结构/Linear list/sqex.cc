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
}

int main()
{
    Sqlist L;
    Elemtype e,e0;
    Status i;
    int j,k;
    InintList(L);
    printf("?????????L??????L.elem=%u L.leng =%d L.listsize=%d\n",L.elem,L.length,L.listsize);
    
    //???L?????????????????????1???5?????????????????????????????????5?????????
    for(j = 1;j <= 5;++j)
        ListInsert(L,1,j);
    for(j = 1;j <= 5;++j){
        GetElem(L,j,e);
        printf("%d ",e);
    }
    printf("\n");

    printf("L.elem=%u L.length=%d L.listsize=%d\n",L.elem,L.length,L.listsize);
    
    //??????L????????????;
    if(ListEmpty(L) == 1)
        i = 1;
    else
        i = 0;
    printf("L????????????i=%d(1:??? 0:???)\n",i);
    
    //??????L;
    ClearList(L);
    printf("??????L??????L.elem=%u L.length=%d L.listsize=%d\n",L.elem,L.length,L.listsize);
    
    //??????L????????????;
    if(ListEmpty(L) == 1)
        i = 1;
    else
        i = 0;
    printf("L????????????i=%d(1:??? 0:???)\n",i);
    
    //???L?????????????????????1???10,??????????????????????????????10?????????
    for(j = 1;j <= 10;++j)
        ListInsert(L,L.length + 1,j);
    for(j = 1;j <= L.length;++j){
        GetElem(L,j,e);
        printf("%d ",e);
    }
    printf("\n");

    //???L???????????????0,??????????????????????????????11?????????
    ListInsert(L,1,0);
    for(j = 1;j <= L.length;++j){
        GetElem(L,j,e);
        printf("%d ",e);
    }
    printf("\n");
    printf("L.elem=%u(???????????????) L.length=%d(??????) L.listsize=%d(??????)\n",L.elem,L.length,L.listsize);

    // ?????????????????????5????????????????????????????????????
    GetElem(L,5,e);
    printf("%d\n",e);

    for(j = 3;j <= 4;++j){
        k = LocatedElem(L,j,comp);
        if(k)
            printf("???%d??????????????????%d?????????\n",k,j);
        else
            printf("????????????%d??????????????????\n",j);
    }

    for(j = 1;j <= 2;++j){
        GetElem(L,j,e0);
        PriorElem(L,e0,e);   
        if(PriorElem(L,e0,e) == 0)
            printf("??????%d?????????\n",e0);
        else
            printf("??????%d???????????????%d\n",e0,e);
    }

    // ?????????k
    k = L.length;
     for(j=k+1;j>=k;j--){  
        i = ListDelete(L,j,e);
        if(i==ERROR)
            printf("?????????%d???????????????\n",j);
        else
            printf("????????????????????????%d\n",e);
    }
    printf("????????????L????????????");
    for(j = 1;j <= L.length;++j){
        printf("%d ",L.elem[j - 1]);
    }
    printf("\n");

     // ?????????????????????visit()?????????????????????
    ListTraverse(L,vist);
    printf("\n");

    // ?????????????????????dbl()???????????????2
     ListTraverse(L,db);
    // ?????????????????????visit()?????????????????????
    ListTraverse(L,vist);
    printf("\n");

    //??????L
    DestoryList(L);
    printf("??????L??????L.elem=%u L.length=%d L.listsize=%d\n",L.elem,L.length,L.listsize);


    //??????2.1
    Sqlist La;
    Sqlist Lb;
    InintList(La);
    InintList(Lb);
    printf("??????La:\n");
    for(int i = 1;i <= 6;++i){
        Elemtype x;
        scanf("%d",&x);
        ListInsert(La,i,x);
    }
    printf("??????Lb:\n");
    for(int i = 1;i <= 6;++i){
        Elemtype x;
        scanf("%d",&x);
        ListInsert(Lb,i,x);
    }
 
    printf("La: ");
    for(int i = 1;i <= La.length;++i)
        printf("%d ",La.elem[i - 1]);
    puts("");
    printf("Lb: ");
    for(int i = 1;i <= Lb.length;++i)
        printf("%d ",Lb.elem[i - 1]);
    puts("");

    for(int i = 1;i <= Lb.length;++i){
         GetElem(Lb,i,e);
         if(LocatedElem(La,e,equal) == 0){
            int pos = La.length + 1;
            ListInsert(La,pos,e);
         }
    }
    printf("??????????????????: ");
    for(int i = 1;i <= La.length;++i)
        printf("%d ",La.elem[i - 1]);
    puts("");

    DestoryList(La);
    DestoryList(Lb);

    //??????2.2
    puts("");
    Sqlist Lc;
    InintList(La);
    InintList(Lb);
    InintList(Lc);

    printf("??????La:\n");
    for(int i = 1;i <= 6;++i){
        Elemtype x;
        scanf("%d",&x);
        ListInsert(La,i,x);
    }

    printf("??????Lb:\n");
    for(int i = 1;i <= 6;++i){
        Elemtype x;
        scanf("%d",&x);
        ListInsert(Lb,i,x);
    }
    
    i = j = 1,k = 0;
    Elemtype ai,bi;
    int lena = La.length;
    int lenb = Lb.length;

    while(i <= La.length && j <= Lb.length){
        GetElem(La,i,ai);
        GetElem(Lb,j,bi);
        if(ai < bi)
            ListInsert(Lc,++k,ai),++i;
        else
            ListInsert(Lc,++k,bi),++j;
    }

    while(i <= La.length){
         GetElem(La,i++,ai);
         ListInsert(Lc,++k,ai);
    }
    while(j <= Lb.length){
        GetElem(Lb,j++,bi);
        ListInsert(Lc,++k,bi);
    }

    printf("La: ");
    for(int i = 1;i <= La.length;++i)
        printf("%d ",La.elem[i - 1]);
    puts("");
    printf("Lb: ");
    for(int i = 1;i <= Lb.length;++i)
        printf("%d ",Lb.elem[i - 1]);
    puts("");
    printf("Lc: ");
    for(int i = 1;i <= Lc.length;++i)
        printf("%d ",Lc.elem[i - 1]);
    puts("");
}
