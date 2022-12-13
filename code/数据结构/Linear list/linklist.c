#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int status;
typedef int elemtype;

typedef struct Node
{
    elemtype data;
    struct Node *next;
}Node;

typedef struct
{
    int len;
    Node *next;
}*Linklist;

status InitList(Linklist *L)
{
    Linklist p = (Linklist)malloc(sizeof(Linklist));
    Node *q = (Node *)malloc(sizeof(Node));
    q->next = NULL;
    p->next = q;
    p->len = 0;
    (*L) = p;
    return OK;
}

status GetElem(Linklist *L,elemtype *e,int pos)
{
    if(pos < 1 || pos > (*L)->len)
        return ERROR;
    Node *p = (*L)->next;
    int j = 0;
    while(p && j < pos){
        p = p->next;
        j++;
    }
    if(!p || j > pos)
        return ERROR;
    *e = p->data;
    return OK;
}

status ListInsert(Linklist *L,elemtype e,int pos)
{
    if(pos < 1 || pos > (*L)->len + 1)
        return ERROR;
    Node *p = (*L)->next;
    int j = 0;
    while(p && j < pos - 1){
        p = p->next;
        j++;
    }
    if(!p || j > pos - 1){
        return ERROR;
    }
    Node *q = (Node *)malloc(sizeof(Node));
    q->next = p->next;
    q->data = e;
    p->next = q;
    (*L)->len++;
    return OK;
}

status ListDelete(Linklist *L,elemtype *e,int pos)
{
    if(pos < 1 || pos > (*L)->len)
        return ERROR;
    Node *p = (*L)->next;
    Node *q;
    int j = 0;
    while(p && j < pos - 1){
        p = p->next;
        j++;
    }
    if(!p || j > pos - 1)
        return ERROR;
    q = p->next;
    p->next = q->next;
    free(q);
    (*L)->len--;
    return OK;
}

status ClearList(Linklist *L)
{
    Node *p = (*L)->next,*q;
    while(p != NULL){
        q = p;
        p = p->next;
        free(q);
    }
    (*L)->next->next = NULL;
    (*L)->len = 0;
    return OK;
}

void PrintList(Linklist L)
{
    Node *p = L->next->next;
    for(int i = 0;i < L->len;++i){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    Linklist L;
    InitList(&L);
    for(int i = 1;i <= 10;++i){
        ListInsert(&L,i,i);
    }
    PrintList(L);
    elemtype e;
    ListDelete(&L,&e,5);
    PrintList(L);
    GetElem(&L,&e,7);
    printf("%d\n",e);
}