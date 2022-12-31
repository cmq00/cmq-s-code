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
   L = (LinkList)malloc(sizeof(LNode));
   L->next = NULL;
   return OK;
}

int ListLength(LinkList L)
{
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


Status ListInsert(LinkList L,int i,ElemType e)
{ 
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


Status ListTraverse(LinkList L)
{
   LNode *p = L->next;
   while(p != NULL){
      if(p->next == NULL)
         cout << p->data;
      else
         cout << p->data << " ";
      p = p->next;
   }
   return OK;
}

int main()
{
    ElemType e;int n;
    LinkList La,Lb,Lc;
    InintList(La);
    InintList(Lb);
    InintList(Lc);
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> e;
        ListInsert(La,ListLength(La) + 1,e);
    }
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> e;
        ListInsert(Lb,ListLength(Lb) + 1,e);
    }
    char ch;
    cin >> ch;
    ElemType i = 1,j = 1,k = 0;
    ElemType ai,bi;
    while(i <= ListLength(La) && j <= ListLength(Lb)){
        GetElem(La,i,ai);
        GetElem(Lb,j,bi);
        if(ai < bi)
            ListInsert(Lc,++k,ai),++i;
        else if(ai > bi)
            ListInsert(Lc,++k,bi),++j;
         else if(ai == bi){
            ListInsert(Lc,++k,ai);
            ++i;++j;
         }
    }
    while(i <= ListLength(La)){
        GetElem(La,i++,ai);
        ListInsert(Lc,++k,ai);
    }
     while(j <= ListLength(Lb)){
        GetElem(Lb,j++,bi);
        ListInsert(Lc,++k,bi);
    }
    ListTraverse(Lc);
}



