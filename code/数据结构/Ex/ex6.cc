#include <bits/stdc++.h>

using namespace std;
 
typedef int Status;
typedef int Elemtype;

typedef struct 
{ 
    Elemtype *a;
    int len;
    int listsize;
}Sqlist;

void vist(Elemtype &c)
{
    printf("%d ",c);
}

Status InintList(Sqlist &L)
{
    L.a = (Elemtype *)malloc(1004 * sizeof(Elemtype));
    L.listsize = 1004;
    if(!L.a)
        exit(OVERFLOW);
    L.len = 0;
    return 1;
}

Status ClearList(Sqlist &L)
{
    L.len = 0;
    return 1;
}

void Insertsort(Sqlist &L)
{
    int j;
    for(int i = 2;i <= L.len;++i){
        if(L.a[i] < L.a[i - 1]){
            L.a[0] = L.a[i];
            L.a[i] = L.a[i - 1];
            for(j = i - 2;L.a[0] < L.a[j];--j){
                L.a[j + 1] = L.a[j];
            }
            L.a[j + 1] = L.a[0];
        }
    }
}

void BubbleSort(Sqlist &L)
{
    for(int i = 1;i <= L.len - 1;++i){
        for(int j = 1;j <= L.len - i;++j){
            if(L.a[j] > L.a[j + 1])
                swap(L.a[j],L.a[j + 1]);
        }
    }
}

void SelectSort(Sqlist &L)
{
    int pos;
    for(int i = 1;i <= L.len;++i){
        int maxx = 0x3f3f3f;
        for(int j = i;j <= L.len;++j){
            if(L.a[j] < maxx){
                pos = j;
                maxx = L.a[j];
            }
        }
        if(i != pos)
            swap(L.a[i],L.a[pos]);
    }
}

int Partition(Sqlist &L,int l,int r)
{
    L.a[0] = L.a[l];
    int p = L.a[l];
    while(l < r){
        while(l < r && L.a[r] >= p)
            --r;
        L.a[l] = L.a[r];
        while(l < r && L.a[l] <= p)
            ++l;
        L.a[r] = L.a[l];
    }
    L.a[l] = L.a[0];
    return l;
}

void QSort(Sqlist &L,int l,int r)
{       
    if(l < r){
        int p = Partition(L,l,r);
        QSort(L,l,p - 1);
        QSort(L,p + 1,r);
    }
}


void CopyList(Sqlist L,Sqlist &T)
{
    T.len = L.len;
    for(int i = 1;i <= L.len;++i)
        T.a[i] = L.a[i];
}

Status ListTraverse(Sqlist L,void(*vi)(Elemtype&))
{
   for(int i = 1;i <= L.len;++i){
       (*vi)(L.a[i]);
   }
   return 1;
}

int main()
{
    Sqlist L,T;
    InintList(L),InintList(T);
    int n,e;
    puts("输入数据个数：");
    cin >> n;
    L.len = n;
    puts("输入数据：");
    for(int i = 1;i <= n;++i){
        cin >> e;
        L.a[i] = e;
    }

    puts("直接插入排序：");
    CopyList(L,T);
    Insertsort(T);
    ListTraverse(T,vist);
    puts("");
    ClearList(T);

    puts("冒泡排序：");
    CopyList(L,T);
    BubbleSort(T);
    ListTraverse(T,vist);
    puts("");
    ClearList(T);

    puts("选择排序：");
    CopyList(L,T);
    SelectSort(T);
    ListTraverse(T,vist);
    puts("");
    ClearList(T);

    puts("快速排序：");
    CopyList(L,T);
    QSort(T,1,T.len);
    ListTraverse(T,vist);
    puts("");
    ClearList(T);
}
