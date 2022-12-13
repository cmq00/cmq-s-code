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
   ElemType e,e0;
   Status i;
   int j,k;
   InintList(L);

   //在L的表头依次插入1～5
   for(i = 1;i <= 5;++i){
      ListInsert(L,1,i);
   }
   printf("在L的表头依次插入1～5后：L= ");
   // 依次对元素调用visit()，输出元素的值
   ListTraverse(L,visit);
   puts("");

   i=ListEmpty(L);
   printf("L是否空：i=%d(1:是 0:否)\n",i);

   i=ClearList(L);
   printf("清空L后：L=");
   ListTraverse(L,visit);
   puts("");
   
   i=ListEmpty(L);
   printf("L是否空：i=%d(1:是 0:否)\n",i);

   //在L的表尾依次插入1～10  
   for(i = 1;i <= 10;++i){
      ListInsert(L,ListLength(L) + 1,i);
   }
   printf("在L的表尾依次插入1～10后：L=");
   ListTraverse(L,visit);
   puts("");
   
   GetElem(L,5,e);
   printf("第5个元素的值为：%d\n",e);

   for(j=0;j<=1;j++){
     k=LocateElem(L,j,comp);
     if(k)
       printf("第%d个元素的值为%d\n",k,j);
     else
       printf("没有值为%d的元素\n",j);
   }

   for(j=1;j<=2;j++){
     // 把第j个数据赋给e0
     GetElem(L,j,e0);
     // 求e0的前驱
     PriorElem(L,e0,i);
     if(i==INFEASIBLE)
       printf("元素%d无前驱\n",e0);
     else
       printf("元素%d的前驱为：%d\n",e0,i);
   }

   for(j=ListLength(L)-1;j<=ListLength(L);j++){
      // 把第j个数据赋给e0
      GetElem(L,j,e0);
      // 求e0的后继
      NextElem(L,e0,i);
     if(i==INFEASIBLE)
       printf("元素%d无后继\n",e0);
     else
       printf("元素%d的后继为：%d\n",e0,i);
   }

   // 求表长k
   k = ListLength(L);
   cout << "k :" << k << endl;
   for(j=k+1;j>=k;j--){
      // 删除第j个数据
      ListDelete(L,j,i);
      if(i == ERROR)
          printf("删除第%d个数据失败\n",j);
      else
          printf("删除的元素为：%d\n",i);
   }
   printf("依次输出L的元素：");
   ListTraverse(L,visit);
   puts("");

   DestroyList(L);
   printf("销毁L后：L=%u\n",L);

}



