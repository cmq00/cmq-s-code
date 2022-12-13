#include <bits/stdc++.h>

using namespace std;

typedef char TElemType;
typedef int Status;

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;//左右孩子指针
}BiTNode,*BiTree;


Status visit(TElemType e)
{
    cout << e << " ";
    return 1;
}

char s[100];
int n = 1;

void CreateBiTree(BiTree &T,int i)
{
    if(s[i] == '0'){
        T = NULL;
        return;
    }
     T = (BiTNode*)malloc(sizeof(BiTNode));
     T->data = s[i];
     T->lchild = NULL;
     T->rchild = NULL;
     if(i * 2 <= n)
        CreateBiTree(T->lchild,i * 2);
    if(i * 2 + 1 <= n)
        CreateBiTree(T->rchild,i * 2 + 1);
}

void CountLeaf(BiTree T,int &cnt)
{
    if(T){
        if(!T->lchild && !T->rchild)
            cnt++;
        CountLeaf(T->lchild,cnt);
        CountLeaf(T->rchild,cnt);
    }
}

int main()
{
    BiTree T;
    char ch;
    while(cin >> ch){
        if(ch == '#')
            break;
        s[n++] = ch;
    }
    CreateBiTree(T,1);
    int cnt = 0;
    CountLeaf(T,cnt);
    cout << cnt << endl;
    return 0;
}