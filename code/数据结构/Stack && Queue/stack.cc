#include <stdio.h>
#include <stdlib.h>

#define stack_Init_Size 100
#define stackincrement 10

#define ERROR 0
#define OK 1
#define OVERFLOW -2

typedef int elemType;
typedef int status;

typedef struct 
{
    elemType *base;
    elemType *top;
    int stacksize;
}sqstack;

status InitStack(sqstack &s)
{
    s.base = (elemType *)malloc(stack_Init_Size * sizeof(elemType));
    if(!s.base)
        return ERROR;
    s.top = s.base;
    s.stacksize = stack_Init_Size;
    return OK;
}

status GetTop(sqstack &s,elemType &e)
{
    if(s.top == s.base)
        return ERROR;
    e = *(s.top - 1);
    return OK;
}

status Push(sqstack &s,elemType e)
{
    if(s.top - s.base > s.stacksize){
        s.base = (elemType *)realloc(s.base,(stack_Init_Size + stackincrement) * sizeof(elemType));
        if(!s.base)
            exit(OVERFLOW);
        s.stacksize += stackincrement;
        s.top = s.base + s.stacksize;
    }
    *(s.top) = e;
    s.top++;
    return OK;
}

status Pop(sqstack &s,elemType &e)
{
    if(s.base == s.top)
        return ERROR;
    s.top--;
    e = *(s.top);
    return OK;
}

int main()
{
    sqstack s;
    InitStack(s);
    for(int i = 1;i <= 5;++i){
        Push(s,i);
    }
    elemType e = 0;
    for(int i = 1;i <= 5;++i){
        Pop(s,e);
        printf("%d\n",e);
    }
    return 0;
}



