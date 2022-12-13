#include <bits/stdc++.h>

using namespace std;

#define stack_Init_Size 100
#define stackincrement 10

#define ERROR 0
#define OK 1
#define OVERFLOW -2
#define FALSE -1

typedef char ElemType;
typedef int Status;

typedef struct 
{
    ElemType *base;
    ElemType *top;
    int stacksize;
}Sqstack;

Status InitStack(Sqstack &s)
{
    s.base = (ElemType *)malloc(stack_Init_Size * sizeof(ElemType));
    if(!s.base)
        return ERROR;
    s.top = s.base;
    s.stacksize = stack_Init_Size;
    return OK;
}

Status DestoryStack(Sqstack &s)
{
    if(s.base){
        delete s.base;
        s.stacksize = 0;
        s.base = NULL;
        s.top = NULL;
        return OK;
    }
    return ERROR;
}

Status ClearStack(Sqstack &s)
{
    if(s.base)
        s.top = s.base;
    return OK;
}

Status StackEmpty(Sqstack s)
{
    if(s.top == s.base)
        return OK;
    return -1;
}

Status StackLength(Sqstack s)
{
    return s.top - s.base;
}


Status GetTop(Sqstack &s,ElemType &e)
{
    if(s.top == s.base)
        return ERROR;
    e = *(s.top - 1);
    return OK;
}

Status Push(Sqstack &s,ElemType e)
{
    if(s.top - s.base > s.stacksize){
        s.base = (ElemType *)realloc(s.base,(stack_Init_Size + stackincrement) * sizeof(ElemType));
        if(!s.base)
            exit(OVERFLOW);
        s.stacksize += stackincrement;
        s.top = s.base + s.stacksize;
    }
    *(s.top) = e;
    s.top++;
    return OK;
}

Status Pop(Sqstack &s,ElemType &e)
{
    if(s.base == s.top)
        return ERROR;
    s.top--;
    e = *(s.top);
    return OK;
}

Status StackTraverse(Sqstack &s,Status(*visit)(ElemType))
{
    int len = StackLength(s);
    for(int i = 0;i < len;++i){
        visit(s.base[i]);
    }
    puts("");
    return OK;
}

Status visit(ElemType e)
{
    cout << e << " ";
    return OK;
}

int main()
{
    Sqstack s;
    int n;
    ElemType e,e0,e1;
    InitStack(s);//初始化
    printf("输入表达式：\n");
    while(scanf("%c",&e) && e != '\n'){
        if(StackEmpty(s) == 1){//如果栈为空，直接入栈
            Push(s,e);
            continue;
        }
        GetTop(s,e0);
        if(e == ')' && e0 == '(')
            Pop(s,e1);
        else if(e == '}' && e0 == '{')
            Pop(s,e1);
        else if(e == ']' && e0 == '[')
            Pop(s,e1);
        else
            Push(s,e);
    }
    if(StackEmpty(s) == 1)//如果栈为空，说明是一个合法的括号序列
        puts("yes");
    else
        puts("no");
}