#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

#define stack_Init_Size 100
#define stackincrement 10

#define ERROR 0
#define OK 1
//#define OVERFLOW -2
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
        //if(!s.base)
            //exit(OVERFLOW);
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
    Sqstack t;
    InitStack(s);
    InitStack(t);
    ElemType e;
    ElemType e0;
    char ss[1000];
    while(~scanf("%s",ss)){
        //cout << ss << endl;
        for(int i = 0;i < strlen(ss);++i){
            Push(s,ss[i]);
        }
    GetTop(s,e);
    while(e != '&'){//将‘&’之前的元素压入到t中
        Push(t,e);
        Pop(s,e0);
        GetTop(s,e);
    }
    Pop(s,e);
    bool f = 1;
    if(StackLength(s) != StackLength(t)){//长度不相等，直接不满足
        f = 0;
    }
    while(StackEmpty(s) == -1){//依次比较栈顶元素
        Pop(s,e);
        Pop(t,e0);
        if(e != e0){//如果有不相等，则不满足
           f = 0;
        }
    }
    ClearStack(s);
    ClearStack(t);
    if(f)
        puts("YES");
    else
        puts("NO");
    }
    int a = 1/ 2;
   return 0;
}