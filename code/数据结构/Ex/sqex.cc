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
    printf("初始化L后：L.elem=%u L.leng =%d L.listsize=%d\n",L.elem,L.length,L.listsize);
    
    //在L的表头依次插入1～5，并且在屏幕上依次输出5个元素
    for(j = 1;j <= 5;++j)
        ListInsert(L,1,j);
    for(j = 1;j <= 5;++j){
        GetElem(L,j,e);
        printf("%d ",e);
    }
    printf("\n");

    printf("L.elem=%u L.length=%d L.listsize=%d\n",L.elem,L.length,L.listsize);
    
    //判断L是否为空;
    if(ListEmpty(L) == 1)
        i = 1;
    else
        i = 0;
    printf("L是否空：i=%d(1:是 0:否)\n",i);
    
    //清空L;
    ClearList(L);
    printf("清空L后：L.elem=%u L.length=%d L.listsize=%d\n",L.elem,L.length,L.listsize);
    
    //判断L是否为空;
    if(ListEmpty(L) == 1)
        i = 1;
    else
        i = 0;
    printf("L是否空：i=%d(1:是 0:否)\n",i);
    
    //在L的表尾依次插入1～10,并且在屏幕上依次输出10个元素
    for(j = 1;j <= 10;++j)
        ListInsert(L,L.length + 1,j);
    for(j = 1;j <= L.length;++j){
        GetElem(L,j,e);
        printf("%d ",e);
    }
    printf("\n");

    //在L的表头插入0,并且在屏幕上依次输出11个元素
    ListInsert(L,1,0);
    for(j = 1;j <= L.length;++j){
        GetElem(L,j,e);
        printf("%d ",e);
    }
    printf("\n");
    printf("L.elem=%u(有可能改变) L.length=%d(改变) L.listsize=%d(改变)\n",L.elem,L.length,L.listsize);

    // 取线性表中的第5个元素，并且在屏幕上输出
    GetElem(L,5,e);
    printf("%d\n",e);

    for(j = 3;j <= 4;++j){
        k = LocatedElem(L,j,comp);
        if(k)
            printf("第%d个元素的值为%d的平方\n",k,j);
        else
            printf("没有值为%d的平方的元素\n",j);
    }

    for(j = 1;j <= 2;++j){
        GetElem(L,j,e0);
        PriorElem(L,e0,e);   
        if(PriorElem(L,e0,e) == 0)
            printf("元素%d无前驱\n",e0);
        else
            printf("元素%d的前驱为：%d\n",e0,e);
    }

    // 求表长k
    k = L.length;
     for(j=k+1;j>=k;j--){  
        i = ListDelete(L,j,e);
        if(i==ERROR)
            printf("删除第%d个数据失败\n",j);
        else
            printf("删除的元素值为：%d\n",e);
    }
    printf("依次输出L的元素：");
    for(j = 1;j <= L.length;++j){
        printf("%d ",L.elem[j - 1]);
    }
    printf("\n");

     // 依次对元素调用visit()，输出元素的值
    ListTraverse(L,vist);
    printf("\n");

    // 依次对元素调用dbl()，元素值乘2
     ListTraverse(L,db);
    // 依次对元素调用visit()，输出元素的值
    ListTraverse(L,vist);
    printf("\n");

    //销毁L
    DestoryList(L);
    printf("销毁L后：L.elem=%u L.length=%d L.listsize=%d\n",L.elem,L.length,L.listsize);


    //算法2.1
    Sqlist La;
    Sqlist Lb;
    InintList(La);
    InintList(Lb);
    printf("输入La:\n");
    for(int i = 1;i <= 6;++i){
        Elemtype x;
        scanf("%d",&x);
        ListInsert(La,i,x);
    }
    printf("输入Lb:\n");
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
    printf("最终插入结果: ");
    for(int i = 1;i <= La.length;++i)
        printf("%d ",La.elem[i - 1]);
    puts("");

    DestoryList(La);
    DestoryList(Lb);

    //算法2.2
    puts("");
    Sqlist Lc;
    InintList(La);
    InintList(Lb);
    InintList(Lc);

    printf("输入La:\n");
    for(int i = 1;i <= 6;++i){
        Elemtype x;
        scanf("%d",&x);
        ListInsert(La,i,x);
    }

    printf("输入Lb:\n");
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
