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

int main()
{
    char a[300];
    SString S;
    gets(a);
    StrAssign(S,a);
    cout << int(S[0]);
}