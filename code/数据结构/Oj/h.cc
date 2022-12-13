#include <bits/stdc++.h>

using namespace std;

#define TRUE 1
#define ERROR 0
#define OK 1
#define FAlSE 0
#define INFEASIBLE -1

typedef int Status;

typedef struct
{
    char *ch;
    int length;
}HString;

void PrintStr(HString S)
{
    for(int i = 0;i < S.length;++i)
        cout << S.ch[i];
}

Status StrAssign(HString &T,char *chars)
{
    int len = strlen(chars);
    //T.ch = (char*)malloc(len * sizeof(char));
    // if(T.ch){
    //     free(T.ch);
    //     T.ch = NULL;
    // }
    if(!len){
        T.ch = NULL;
        T.length = 0;
    }
    else{
        T.ch = (char*)malloc(len * sizeof(char));
        // if(!T.ch)
        //     exit(OVERFLOW);
        for(int i = 0;i < len;++i)
            T.ch[i] = chars[i];
        T.length = len;
    }
    return OK;
}

Status StrLength(HString S)
{
    return S.length;
}

Status StrCompare(HString S,HString T)
{
    int i;
    for(i = 0;i < S.length && i < T.length;++i){
        if(S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];
    }
    return S.length - T.length;
}

Status ClearString(HString &S)
{
    if(S.ch){
        free(S.ch);
        S.ch = NULL;
    }
    S.length = 0;
    return OK;
}

Status Concat(HString &T,HString S1,HString S2)
{
    if(T.ch)
        free(T.ch);
    T.ch = (char*)malloc((S1.length + S2.length) * sizeof(char));
    // if(!T.ch)
    //     exit(OVERFLOW);
    for(int i = 0;i <= S1.length - 1;++i)
        T.ch[i] = S1.ch[i];
    for(int i = 0;i < S2.length;++i)
        T.ch[i + S1.length] = S2.ch[i];
    T.length = S1.length + S2.length;
    return OK; 
}

Status SubString(HString &Sub,HString S,int pos,int len)
{
    if(pos < 1 || pos > S.length || len < 0 || len > S.length - pos + 1)
        return ERROR;
    //if(Sub.ch)
        //free(Sub.ch);
    if(!len){
        Sub.ch = NULL;
        Sub.length = 0;
    }
    else{
        Sub.ch = (char*)malloc(len * sizeof(char));
        for(int i = 0;i < len;++i)
            Sub.ch[i] = S.ch[pos + i - 1];
        Sub.length = len;
    }
    return OK;
}

Status Index(HString S,HString T,int pos)
{
    HString Sub;
    if(pos > 0){
        int n = S.length,m = T.length,i = pos;
        while(i < n - m + 1){
            SubString(Sub,S,i,m);  
            if(StrCompare(Sub,T) != 0)
                i++;
            else
                return i;
        }
    }
    return -1;
}

Status StrInsert(HString &S,int pos,HString T)
{
    S.ch = (char*)malloc((S.length + T.length) * sizeof(char));
    for(int i = S.length - 1;i >= pos - 1;--i)
        S.ch[i + T.length] = S.ch[i];
    for(int i = pos - 1;i < pos + T.length - 1;++i)
        S.ch[i] = T.ch[i - pos + 1];
    S.length += T.length;
    return OK;
}

Status StrDelete(HString &S,int pos,int len)
{
     if(pos < 1 || pos > S.length || len < 0 || len > S.length - pos + 1)    
        return ERROR;
    for(int i = pos + len - 1;i < S.length;++i)
        S.ch[i - len] = S.ch[i];
    S.length -= len;
    return OK;
}

Status Replace(HString &S,HString T,HString V)
{
    int i = 1;
    if(S.length == 0)
        return ERROR;
    do{
        cout << "!" << endl;
        i = Index(S,T,i);
        cout << i << endl;
        if(i != -1){
            StrDelete(S,i,StrLength(T));
            StrInsert(S,i,V);
            i += V.length;
        }
    }while(i != -1);
    return OK;
}

int main()
{
    HString S;
    char a[1000];
    gets(a);
    StrAssign(S,a);
    int pos,len;
    cin >> pos >> len;
    HString Sub;
    SubString(Sub,S,pos,len);
    PrintStr(Sub);
}