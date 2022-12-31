#include <bits/stdc++.h>

using namespace std;

#define OK 1

typedef struct
{
    int *elem;
    int len;
    int listsize;
}Sqlist;

int InitList(Sqlist &L)
{
    L.elem = (int*)malloc(1004 * sizeof(int));
    L.listsize = 1004;
    L.len = 0;
    return OK;
}

int ListInsert(Sqlist &L,int i,int e)
{
    int *q = &(L.elem[i - 1]);
    for(int *p = &(L.elem[L.len - 1]);p >= q;--p){
        *(p + 1) = *p;
    }
    *q = e;
    L.len++;
    return OK;
}

int Search(Sqlist L,int e)
{
    int cnt = 0;
    for(int i = 0;i < L.len;++i){
        if(L.elem[i] == e)
            cnt++;
    }
    return cnt;
}

int main()
{
    Sqlist L;
    InitList(L);
    int e;
    for(int i = 1;;++i){
        cin >> e;
        ListInsert(L,i,e);
        if(getchar() == '\n')
            break; 
    }
    int x;
    cin >> x;
    int cnt = Search(L,x);
    cout << cnt;
    return 0;
}

