#include <bits/stdc++.h>

using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INFEASIBLE -1

typedef int Status;
typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    LNode *next;
}LNode,*LinkList;

Status InintList(LinkList &L)  
{ 
   // 操作结果：构造一个空的线性表L 
   L = (LinkList)malloc(sizeof(LNode));
   L->next = NULL;
   return OK;
}

Status DestroyList(LinkList &L) 
{
   // 初始条件：线性表L已存在。操作结果：销毁线性表L
   delete[] L;
   L->next = NULL;
   return OK;
}

Status ClearList(LinkList L)
{
   // 初始条件：线性表L已存在。操作结果：将L重置为空表
   LNode *p = L->next,*q;
   while(p != NULL){
      q = p;
      p = p->next;
      free(q);
   }
   L->next = NULL;
   return OK;
}

Status ListEmpty(LinkList L)
{
   // 初始条件：线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE
   if(L->next == NULL)
      return TRUE;
   return FALSE;
} 

int ListLength(LinkList L)
{
   //初始条件：线性表L已存在。操作结果：返回L中数据元素个数 
   int len = 0;
   LNode *p = L->next;
   while(p != NULL){
      p = p->next;
      len++;
   }
   return len;
}

Status GetElem(LinkList L,int i,ElemType &e)
{
   // L为带头结点的单链表的头指针。当第i个元素存在时,其值赋给e并返回OK,否则返回ERROR
   int len = ListLength(L);
   if(i < 1 || i > len)
      return ERROR;
   LNode *p = L->next;
   int j = 1;
   while(p && j < i){
      p = p->next;
      j++;
   }
   if(!p || j > i)
      return ERROR;
   e = p->data;
   return OK;
}

int LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType))
{
   LNode *p = L->next;
   int pos = 1;
   while(p != NULL && !(*compare)(p->data,e)){
      p = p->next;
      pos++;
   }
   if(p != NULL)
      return pos;
   return 0;
} 

Status comp(ElemType a,ElemType b)
{  
   // 初始条件: 线性表L已存在,compare()是数据元素判定函数(满足为1,否则为0)
   // 操作结果: 返回L中第1个与e满足关系compare()的数据元素的位序。
   //           若这样的数据元素不存在,则返回值为0
   if(a == b)
      return TRUE;
   return FALSE;
}

Status PriorElem(LinkList L,ElemType cur_e,ElemType &pre_e)
{
   // 初始条件: 线性表L已存在
   // 操作结果: 若cur_e是L的数据元素,且不是第一个,则用pre_e返回它的前驱,
   // 返回OK;否则操作失败,pre_e无定义,返回INFEASIBLE
   int pos = LocateElem(L,cur_e,comp);
   if(pos == 0 || pos == 1){
      pre_e = INFEASIBLE;
      return INFEASIBLE;
   }
   int j = 1;
   LNode *p = L->next;
   while(j < pos - 1){
      p = p->next;
      j++;
   }
   pre_e = p->data;
   return OK;
}

 Status NextElem(LinkList L,ElemType cur_e,ElemType &next_e)
{
   // 初始条件：线性表L已存在
   // 操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，
   // 返回OK;否则操作失败，next_e无定义，返回INFEASIBLE
   int pos = LocateElem(L,cur_e,comp);
   if(pos == 0 || pos == ListLength(L)){
      next_e = INFEASIBLE;
      return INFEASIBLE;
   }
   int j = 1;
   LNode *p = L->next;
   while(j < pos + 1){
      p = p->next;
      j++;
   }
   next_e = p->data;
   return OK;
}

Status ListInsert(LinkList L,int i,ElemType e) // 算法2.9。不改变L
{ 
   // 在带头结点的单链线性表L中第i个位置之前插入元素e
   if(i < 1 || i > ListLength(L) + 1)
      return ERROR;
   LNode *p = L;
   int j = 0;
   while(p && j < i - 1){
      p = p->next;
      j++;
   }
   if(!p || j > i - 1){
      return ERROR;
   }
   LNode *q = (LinkList)malloc(sizeof(LNode));
   q->next = p->next;
   q->data = e;
   p->next = q;
   return OK;
}

Status ListDelete(LinkList L,int i,ElemType &e) // 算法2.10。不改变L
{ // 在带头结点的单链线性表L中，删除第i个元素,并由e返回其值
   if(i < 1 || i > ListLength(L)){
      e = ERROR;
      return ERROR;
   }
   LNode *p = L;
   int j = 0;
   while(p && j < i - 1){
      p = p->next;
      j++;
   }   
   if(!(p->next) || j > i - 1){
      e = ERROR;
      return ERROR;
   }
   LNode *q;
   q = p->next;
   p->next = q->next;
   e = q->data;
   free(q);
   return OK;
}

Status ListTraverse(LinkList L,void(*vi)(ElemType))
{
   // vi的形参类型为ElemType，与bo2-1.cpp中相应函数的形参类型ElemType&不同
   // 初始条件：线性表L已存在
   // 操作结果:依次对L的每个数据元素调用函数vi()。一旦vi()失败,则操作失败
   LNode *p = L->next;
   while(p != NULL){
      vi(p->data);
      p = p->next;
   }
   return OK;
}

void visit(ElemType c)
{
   cout << c << " ";
}

int main()
{
    LinkList L;
    InintList(L);//初始化L
    ElemType e,e0;
    printf("元素个数：");
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> e;
        ListInsert(L,i,e);
    }
    int i = 2;
    while(i <= ListLength(L)){
        GetElem(L,i,e);//取第i个元素
        GetElem(L,i - 1,e0);//取第i - 1个元素
        if(e == e0){
            ListDelete(L,i,e);//如果第i个元素等于第i - 1个元素，则删除第i个元素
        }
        else
            i++;
    }
    ListTraverse(L,visit);//输出L
    puts("");
    return 0;
}