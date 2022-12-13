#include <bits/stdc++.h>

using namespace std;

typedef char TElemType;
typedef int Status;

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;//左右孩子指针
}BiTNode,*BiTree;

void CreateBiTree(BiTree &T)
{
    TElemType e;
    cin >> e;
    if(e == '#')
        T = NULL;
    else{
        T = (BiTNode*)malloc(sizeof(BiTNode));
        T->data = e;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

Status visit(TElemType e)
{
    cout << e << " ";
    return 1;
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
            if(T->lchild != NULL)
                q.push(T->lchild);
            if(T->rchild != NULL)
                q.push(T->rchild);
        }
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

void InOrderTraverse(BiTree T,Status(*visit)(TElemType e))
{
    if(T){
        InOrderTraverse(T->lchild,visit);
        visit(T->data);
        InOrderTraverse(T->rchild,visit);
    }
}

void PostOrderTraverse(BiTree T,Status(*visit)(TElemType e))
{
    if(T){
        PostOrderTraverse(T->lchild,visit);
        PostOrderTraverse(T->rchild,visit);
        visit(T->data);
    }
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

Status Depth(BiTree T)
{
    if(!T)
        return 0;
    else{
        int depthLeft = Depth(T->lchild);
        int depthRight = Depth(T->rchild);
        return 1 + (depthLeft > depthRight?
depthLeft : depthRight);
    }
}


int main()
{
    BiTree T; 
    puts("输入以“#”为左/右子树为空的标志");
    CreateBiTree(T);
    puts("先序遍历：");
    PreOrderTraverse(T,visit);
    puts("");
    puts("中序遍历：");
    InOrderTraverse(T,visit);
    puts("");
    puts("后序遍历：");
    PostOrderTraverse(T,visit);
    puts("");

}//abc##de#g##f###