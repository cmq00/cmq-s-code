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

map<char,int> mp;

vector<ElemType> v;

int main()
{
    mp['+'] = 1;mp['-'] = 1;mp['*'] = 2;mp['/'] = 2;
    ElemType e,e0;
    string t;
    Sqstack s;
    InitStack(s);
    cin >> t;
    for(int i = 0;i < t.size();++i){
        if((t[i] >= 'a' && t[i] <= 'z') || (t[i] >= 'A' && t[i] <= 'Z')){
            v.push_back(t[i]);
            continue;
        }
        if(t[i] == '('){
            Push(s,t[i]);
            continue;
        }
        if(t[i] == ')'){
            GetTop(s,e);
            while(e != '('){
                v.push_back(e);
                Pop(s,e0);
                GetTop(s,e);
            }
            Pop(s,e0);
            continue;
        }
        if(StackEmpty(s) == 1){
            Push(s,t[i]);
        }
        else{
            GetTop(s,e);
            if(mp[e] < mp[t[i]])    
                Push(s,t[i]);
            else{
                while(StackEmpty(s) == -1 &&  mp[e] >= mp[t[i]]){
                    v.push_back(e);
                    Pop(s,e0);
                    if(StackEmpty(s) != -1)
                        break;
                    GetTop(s,e);
                }
                Push(s,t[i]);
            }
        }
    }
    while(StackEmpty(s) == -1){
        Pop(s,e);
        v.push_back(e);
    }
    for(int i = 0;i < v.size();++i){
            cout << v[i];
    }
    //puts("");
    return 0;
}