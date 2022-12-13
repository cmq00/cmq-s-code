#include <bits/stdc++.h>

using namespace std;

typedef char TElemType;
typedef int Status;

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;//左右孩子指针
}BiTNode,*BiTree;

char t[1000][3];

Status visit(TElemType e)
{
    cout << e << " ";
    return 1;
}

void CreateBiTree(BiTree &T,char ch)
{
    TElemType e;
    e = ch;
    if(e == '0')
        T = NULL;
    else{
        T = (BiTNode*)malloc(sizeof(BiTNode));
        T->data = e;
        CreateBiTree(T->lchild,t[ch][1]);
        CreateBiTree(T->rchild,t[ch][2]);
    }
}

void PreOrderTraverse(BiTree T,Status(*visit)(TElemType e))
{
    if(T){
        visit(T->data);
        PreOrderTraverse(T->lchild,visit);
        PreOrderTraverse(T->rchild,visit);
    }
}

void LevelOrderTraverse(BiTree T,Status(*visit)(TElemType e))
{
    if(T){
        queue<BiTNode*> q;
        q.push(T);
        while(!q.empty()){
            T = q.front();
            q.pop();
            visit(T->data);
            if(T->lchild != NULL){
                q.push(T->lchild);
                cout << T->lchild->data << " ";
            }
            if(T->lchild == NULL)
                cout << "0" << " ";
            if(T->rchild != NULL){
                q.push(T->rchild);
                cout << T->rchild->data;
            }
            if(T->rchild == NULL)
                cout << "0";
            puts("");
        }
    }
}

Status Depth(BiTree T)
{
    if(!T)
        return 0;
    else{
        int depthLeft = Depth(T->lchild);
        int depthRight = Depth(T->rchild);
        return 1 + (depthLeft > depthRight?depthLeft : depthRight);
    }
}



int main()
{
    BiTree T;
    TElemType e,a,b,c;
    cin >> e;
    while(cin >> a){
        if(a == '#')
            break;
        cin >> b >> c;
        t[a][1] = c;
        t[a][2] = b;
    }
    CreateBiTree(T,e);
    int dp = Depth(T);
    cout << dp << endl;
}