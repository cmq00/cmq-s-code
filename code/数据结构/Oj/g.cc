#include <bits/stdc++.h>

using namespace std;

#define TRUE 1
#define ERROR 0
#define OK 1
#define FAlSE 0
#define INFEASIBLE -1

#define MAXSTRLEN 255
typedef int Status;
typedef char SString[MAXSTRLEN + 1];

void PrintStr(SString S)
{
    for(int i = 1;i <= S[0];++i){
        cout << S[i];
    }
}

Status StrAssign(SString &S,char *chars)
{
    int len = strlen(chars);
    if(len > MAXSTRLEN)
        return ERROR;
    if(len == 0){
        S[0] = 0;
        return OK;
    }
    for(int j = 1;j <= len;++j){
        S[j] = *(chars + j - 1);
    }
    S[0] = len;
    return OK;
}

Status StrEmpty(SString S)
{
    if(S[0] == 0)
        return 1;
    return -1;
}

Status StrCompare(SString S,SString T)
{
    int i;
    if(S[0] == T[0]){
        for(int i = 1;i <= S[0];++i){
            if(S[i] != T[i])
                return S[i] - T[i];
        }
    }
    return S[0] - T[0];
}

Status StrLength(SString S)
{
    return S[0];
}

Status ClearString(SString &S)
{
    S[0] = 0;
    return OK;
}

Status Concat(SString &T,SString S1,SString S2)
{
    int uncat = 1;
    if(S1[0] + S2[0] <= MAXSTRLEN){
        for(int i = 1;i <= S1[0];++i)
            T[i] = S1[i];
        for(int i = S1[0] + 1,j = 1;j <= S2[0];++j,++i){
            T[i] = S2[j];
        }
        T[0] = S1[0] + S2[0];
    }
    else if(S1[0] < MAXSTRLEN){
        for(int i = 1;i <= S1[0];++i)
            T[i] = S1[i];
        for(int i = S1[0] + 1,j = 1;j <= MAXSTRLEN;++j,++i)
            T[i] = S2[j];
        T[0] = MAXSTRLEN;
        uncat = 0;
    }
    else{
        for(int i = 1;i <= MAXSTRLEN;++i)
            T[i] = S1[i];
        T[0] = S1[0] = MAXSTRLEN;
        uncat = 0;
    }
    return uncat;
}

Status SubString(SString &Sub,SString S,int pos,int len)
{
    if(pos < 1 || pos > S[0] || len < 0 || len > S[0] - pos + 1)\
        return ERROR;
    for(int i = 1;i <= len;++i)
        Sub[i] = S[pos + i - 1];
    Sub[0] = len;
    return OK;
}

Status Index(SString S,SString T,int pos)
{
    SString Sub;
    if(pos > 0){
        int n = S[0],m = T[0],i = pos;
        //cout << "n:" << n << "m:" << m << endl;
        while(i <= n - m + 1){
            //cout << i << endl;
            SubString(Sub,S,i,m);
            if(StrCompare(Sub,T) != 0)
                i++;
            else
                return i;
        }
    }
    return ERROR;
}

Status StrInsert(SString &S,int pos,SString T)
{
    if(S[0] + T[0] > MAXSTRLEN)
        return ERROR;
    for(int i = S[0];i >= pos;--i){
        S[i + T[0]] = S[i];
    }
    for(int i = pos;i < pos + T[0];++i)
        S[i] = T[i - pos + 1];
    S[0] += T[0];
    return OK;
}

Status StrDelete(SString &S,int pos,int len)
{
    if(pos < 1 || pos > S[0] || len < 0 || len > S[0] - pos + 1)    
        return ERROR;
    for(int i = pos + len;i <= S[0];++i)
        S[i - len] = S[i];
    S[0] -= len;
    return OK;
}

Status Replace(SString &S,SString T,SString V)
{
    int i = 1;
    if(StrEmpty(T) == 1){
        return ERROR;
    }
    do{
        i = Index(S,T,i);
        if(i){
            StrDelete(S,i,StrLength(T));
            StrInsert(S,i,V);
            i += StrLength(V);
        }
    }while(i);
    return OK;
}

int main()
{
   SString s;
   char a[300];
   gets(a);
   StrAssign(s,a);
   SString t;
   gets(a);
   StrAssign(t,a);
   int pos;
   cin >> pos;
   StrInsert(s,pos,t);
   PrintStr(s);
}

