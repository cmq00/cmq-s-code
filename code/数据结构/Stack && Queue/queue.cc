#include <bits/stdc++.h>

using namespace std;

#define stack_Init_Size 100
#define stackincrement 10

#define ERROR 0
#define OK 1
#define FAlSE -1
#define OVERFLOW -2

typedef int QElemType;
typedef int Status;

typedef struct QNode
{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct
{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    if(!Q.front)
        exit(OVERFLOW);
    Q.front->next = NULL;
    return OK;
}

Status DestoryQueue(LinkQueue &Q)
{
    while(Q.front){
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }
    return OK;
}



Status ClearQueue(LinkQueue &Q)
{
    return OK;
}

Status QueueEmpty(LinkQueue Q)
{
    if(Q.front == Q.rear)
        return OK;
    return FAlSE;
}

Status QueueLength(LinkQueue Q)
{
    return Q.rear - Q.front;
}

Status GetHead(LinkQueue &Q,QElemType &e)
{
    e = Q.front->data;
    return OK;
}

Status EnQueue(LinkQueue &Q,QElemType e)
{
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if(!p)
        exit(OVERFLOW);
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

Status DeQueue(LinkQueue &Q,QElemType &e)
{
    if(Q.front == Q.rear)
        return -1;
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    p = Q.front;
    Q.front = Q.front->next;
    e = Q.front->data;
    free(p);
    return 1;
}

Status QueueTraverse(LinkQueue Q,void(*vi)(QElemType&))
{
    
}

int main()
{
    
    return 0;
}
