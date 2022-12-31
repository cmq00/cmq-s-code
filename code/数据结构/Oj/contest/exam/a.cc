#include <bits/stdc++.h>

using namespace std;

typedef char TElemType;
typedef int Status;

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;


char s[10004];
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
    if(T && T->data){
        if(!T->lchild && !T->rchild){
            cnt++;
            //cout << T->data << " " << cnt << endl;
        }
        CountLeaf(T->lchild,cnt);
        CountLeaf(T->rchild,cnt);
    }
}

int main()
{
    BiTree T;
    int nn;
    cin >> nn;
    char ch;
    while(cin >> ch){
        if(ch == '#')
            break;
        s[n++] = ch;
    }
    // for(int i = 1;i <= n;++i)
    //     cout << s[i];
    // puts("");
    CreateBiTree(T,1);
    int cnt = 0;
    CountLeaf(T,cnt);
    cout << nn - cnt;

    return 0;
}
