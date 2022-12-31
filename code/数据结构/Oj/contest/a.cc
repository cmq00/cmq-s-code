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

Status InitList(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    return OK;
}

Status ListLength(LinkList L)
{
    int len = 0;
    LNode *p = L->next;
    while(p != NULL){
        p = p->next;
        len++;
    }
    return len;
}


Status ListInsert(LinkList &L,int i,ElemType e)
{
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
        cout << p->data << " ";
        p = p->next;
    }
    puts("");
    return OK;
}

int main()
{
    LinkList L;
    InitList(L);
    int n,maxx = -1;
    ElemType e;
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> e;
        if(e >= maxx)
            maxx = e;
        ListInsert(L,i,e);
    }
    LNode *q = L;
    LNode *p = L->next;
    while(p != NULL){
        if(p->data == maxx){
            q->next = p->next;
        }
        else
            q = q->next;
        p = p->next;
    }
    LNode *pp = L->next;
    while(pp != NULL){
        if(pp->next == NULL)
            cout << pp->data;
        else
            cout << pp->data << " ";
        pp = pp ->next;
    }
    return 0;
}
